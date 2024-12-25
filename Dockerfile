# - Dockerfile for Cytnx CI with CUDA
#
# Build the docker image:
#   docker build -t cytnx_image .
#
# Run the tests within the container:
#   docker run --name cytnx_container --gpus all cytnx_image
#
# Copy the result from the conatiner to the host:
#   docker cp cytnx_container:$CYTNX_BUILD/junit.xml .
#   docker cp cytnx_container:$CYTNX_BUILD/Testing/Temporary/LastTest.log .

FROM nvidia/cuda:12.2.2-devel-ubuntu22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt update -y
RUN apt upgrade -y
RUN apt install -y \
  build-essential \
  ninja-build \
  git \
  wget \
  libssl-dev \
  # Install Boost.
  libboost-all-dev \
  # Install OpenBLAS.
  libopenblas-dev \
  liblapacke-dev \
  # Install Python3.11.
  python3.11 \
  python3.11-dev \
  python3.11-venv

# Install CMake.
ENV CMAKE_ROOT="/home/CMake"
ENV CMAKE_BUILD="$CMAKE_ROOT/build"
WORKDIR /home
RUN git clone https://github.com/Kitware/CMake.git -b v3.31.3
WORKDIR $CMAKE_ROOT
RUN ./bootstrap
RUN make -j $(nproc)
RUN make install

# Set OpenBLAS cmake path.
ENV OPENBLAS_CMAKE_PATH="/usr/lib/x86_64-linux-gnu/openblas-pthread/cmake/openblas"
ENV OPENBLAS_BLAS_LIB="/usr/lib/x86_64-linux-gnu/libopenblas.so"
ENV OPENBLAS_LAPACKE_LIB="/usr/lib/x86_64-linux-gnu/liblapacke.so"

# Install cuTENSOR.
ENV CUTENSOR_ROOT="/usr/lib/x86_64-linux-gnu/libcutensor"
ENV CUTENSOR_INCLUDE_DIR="$CUTENSOR_ROOT/include"
RUN wget https://developer.download.nvidia.com/compute/cuda/repos/ubuntu2204/x86_64/cuda-keyring_1.1-1_all.deb
RUN dpkg -i cuda-keyring_1.1-1_all.deb
RUN apt update -y
RUN apt install -y libcutensor2 libcutensor-dev libcutensor-doc
RUN mkdir -p "$CUTENSOR_INCLUDE_DIR"
RUN ln -s "/usr/include/cutensor.h" "$CUTENSOR_INCLUDE_DIR/cutensor.h"
RUN ln -s "/usr/include/cutensorMg.h" "$CUTENSOR_INCLUDE_DIR/cutensorMg.h"

# Install cuQuantum.
ENV CUQUANTUM_ROOT="/usr/lib/x86_64-linux-gnu/libcuquantum"
ENV CUQUANTUM_LIB_DIR="$CUQUANTUM_ROOT/lib"
ENV CUQUANTUM_INCLUDE_DIR="$CUQUANTUM_ROOT/include"
RUN wget https://developer.download.nvidia.com/compute/cuda/repos/ubuntu2204/x86_64/cuda-keyring_1.1-1_all.deb
RUN dpkg -i cuda-keyring_1.1-1_all.deb
RUN apt update -y
RUN apt install -y cuquantum-cuda-12
RUN ln -s "$CUQUANTUM_ROOT/12" "$CUQUANTUM_LIB_DIR"
RUN mkdir -p "$CUQUANTUM_INCLUDE_DIR"
RUN ln -s "/usr/include/cutensornet.h" "$CUQUANTUM_INCLUDE_DIR/cutensornet.h"
RUN ln -s "/usr/include/custatevec.h" "$CUQUANTUM_INCLUDE_DIR/custatevec.h"

# Install gtest.
ENV GTEST_ROOT="/home/googletest"
ENV GTEST_BUILD="$GTEST_ROOT/build"
WORKDIR /home
RUN git clone https://github.com/google/googletest.git -b v1.15.2
WORKDIR $GTEST_ROOT
RUN cmake -B $GTEST_BUILD -G Ninja
RUN cmake --build $GTEST_BUILD --target install

# Create Python3.11 virtual environment and
# install the dependencies.
ENV VENV_PATH="/home/pyvenv"
RUN python3.11 -m venv $VENV_PATH
ENV PATH="$PATH:$VENV_PATH/bin"
RUN pip3.11 install --upgrade pip
RUN pip3.11 install pybind11
RUN pip3.11 install numpy

# Set pybind11 cmake path.
ENV PYBIND11_CMAKE_PATH="$VENV_PATH/lib/python3.11/site-packages/pybind11/share/cmake/pybind11"

# Build Cytnx.
ENV CYTNX_ROOT=/home/Cytnx
RUN mkdir -p $CYTNX_ROOT
WORKDIR $CYTNX_ROOT
COPY . .
RUN git submodule update --init --recursive

ENV CMAKE_PREFIX_PATH="$OPENBLAS_CMAKE_PATH:$PYBIND11_CMAKE_PATH"
ENV CYTNX_BUILD="$CYTNX_ROOT/build"
ENV ASAN_OPTIONS="protect_shadow_gap=0:replace_intrin=0:detect_leaks=0"
RUN cmake -B $CYTNX_BUILD -G Ninja \
  -D CMAKE_BUILD_TYPE=Debug \
  -D USE_DEBUG=ON \
  -D Python_EXECUTABLE="$(which python3.11)" \
  -D Python_INTERPRETER="$(which python3.11)" \
  -D Python3_EXECUTABLE="$(which python3.11)" \
  -D Python3_INTERPRETER="$(which python3.11)" \
  -D BLAS_LIBRARIES="$OPENBLAS_BLAS_LIB" \
  -D LAPACK_LIBRARIES="$OPENBLAS_LAPACKE_LIB" \
  -D CUTENSOR_ROOT="$CUTENSOR_ROOT" \
  -D CUQUANTUM_ROOT="$CUQUANTUM_ROOT" \
  -D USE_MKL=OFF \
  -D USE_CUDA=ON \
  -D USE_CUTENSOR=ON \
  -D USE_CUQUANTUM=ON \
  -D USE_CUTT=OFF \
  -D USE_MAGMA=OFF \
  -D USE_HPTT=OFF \
  -D RUN_TESTS=ON

WORKDIR $CYTNX_BUILD
ENV EXCLUDED_TESTS_FILE="$CYTNX_ROOT/tests/failed_tests.txt"
CMD cmake --build $CYTNX_BUILD && \
    GTEST_COLOR=1 ctest --output-on-failure --output-junit junit.xml --exclude-from-file "$EXCLUDED_TESTS_FILE"
