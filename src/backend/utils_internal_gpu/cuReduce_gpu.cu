#include "cuReduce_gpu.hpp"

#include <cuComplex.h>

#include "Type.hpp"

namespace cytnx {
  namespace utils_internal {

#define _TNinB_REDUCE_ 512

    template <class X>
    __device__ void warp_unroll(X* smem, int tid) {
      X v = smem[tid];
      __syncwarp();
      v += __shfl_down_sync(0xFFFFFFFFU, v, 16);
      v += __shfl_down_sync(0xFFFFFFFFU, v, 8);
      v += __shfl_down_sync(0xFFFFFFFFU, v, 4);
      v += __shfl_down_sync(0xFFFFFFFFU, v, 2);
      v += __shfl_down_sync(0xFFFFFFFFU, v, 1);
      smem[tid] = v;
      __syncwarp();
    }

    // require, threads per block to be 32*(2^n), n =0,1,2,3,4,5
    template <class T>
    __global__ void cuReduce_kernel(T* out, T* in, cytnx_uint64 Nelem) {
      __shared__ T sD[_TNinB_REDUCE_];  // allocate share mem for each thread
      sD[threadIdx.x] = 0;

      if (blockIdx.x * blockDim.x + threadIdx.x < Nelem) {
        sD[threadIdx.x] = in[blockIdx.x * blockDim.x + threadIdx.x];
      }
      __syncthreads();

      if (blockDim.x >= 1024) {
        if (threadIdx.x < 512) {
          sD[threadIdx.x] += sD[threadIdx.x + 512];
        }
        __syncthreads();
      }
      if (blockDim.x >= 512) {
        if (threadIdx.x < 256) {
          sD[threadIdx.x] += sD[threadIdx.x + 256];
        }
        __syncthreads();
      }
      if (blockDim.x >= 256) {
        if (threadIdx.x < 128) {
          sD[threadIdx.x] += sD[threadIdx.x + 128];
        }
        __syncthreads();
      }
      if (blockDim.x >= 128) {
        if (threadIdx.x < 64) {
          sD[threadIdx.x] += sD[threadIdx.x + 64];
        }
        __syncthreads();
      }
      if (blockDim.x >= 64) {
        if (threadIdx.x < 32) {
          sD[threadIdx.x] += sD[threadIdx.x + 32];
        }
        __syncthreads();
      }

      if (threadIdx.x < 32) warp_unroll(sD, threadIdx.x);
      __syncthreads();

      if (threadIdx.x == 0) out[blockIdx.x] = sD[0];  // write to global for block
    }
    //=======================

    __device__ void warp_unroll(cuDoubleComplex* smem, int tid) {
      double v = reinterpret_cast<double*>(smem)[tid];
      v += __shfl_down_sync(0xFFFFFFFFU, v, 16);
      v += __shfl_down_sync(0xFFFFFFFFU, v, 8);
      v += __shfl_down_sync(0xFFFFFFFFU, v, 4);
      v += __shfl_down_sync(0xFFFFFFFFU, v, 2);
      // Retain two double values, which together represent one complex double number.
      reinterpret_cast<double*>(smem)[tid] = v;
    }
    __global__ void cuReduce_kernel_cd(cuDoubleComplex* out, cuDoubleComplex* in,
                                       cytnx_uint64 Nelem) {
      __shared__ cuDoubleComplex sD[_TNinB_REDUCE_];  // allocate share mem for each thread
      sD[threadIdx.x] = make_cuDoubleComplex(0, 0);

      if (blockIdx.x * blockDim.x + threadIdx.x < Nelem) {
        sD[threadIdx.x] = in[blockIdx.x * blockDim.x + threadIdx.x];
      }
      __syncthreads();

      if (blockDim.x >= 1024) {
        if (threadIdx.x < 512) {
          sD[threadIdx.x].x += sD[threadIdx.x + 512].x;
          sD[threadIdx.x].y += sD[threadIdx.x + 512].y;
        }
        __syncthreads();
      }
      if (blockDim.x >= 512) {
        if (threadIdx.x < 256) {
          sD[threadIdx.x].x += sD[threadIdx.x + 256].x;
          sD[threadIdx.x].y += sD[threadIdx.x + 256].y;
        }
        __syncthreads();
      }
      if (blockDim.x >= 256) {
        if (threadIdx.x < 128) {
          sD[threadIdx.x].x += sD[threadIdx.x + 128].x;
          sD[threadIdx.x].y += sD[threadIdx.x + 128].y;
        }
        __syncthreads();
      }
      if (blockDim.x >= 128) {
        if (threadIdx.x < 64) {
          sD[threadIdx.x].x += sD[threadIdx.x + 64].x;
          sD[threadIdx.x].y += sD[threadIdx.x + 64].y;
        }
        __syncthreads();
      }
      if (blockDim.x >= 64) {
        if (threadIdx.x < 32) {
          sD[threadIdx.x].x += sD[threadIdx.x + 32].x;
          sD[threadIdx.x].y += sD[threadIdx.x + 32].y;
        }
        __syncthreads();
      }
      if (blockDim.x >= 32) {
        if (threadIdx.x < 16) {
          sD[threadIdx.x].x += sD[threadIdx.x + 16].x;
          sD[threadIdx.x].y += sD[threadIdx.x + 16].y;
        }
        __syncthreads();
      }

      // A complex double consists of two double values. Up to 32 double values (equivalent to 16
      // complex double numbers) may need to be reduced.
      if (threadIdx.x < 32) warp_unroll(sD, threadIdx.x);
      __syncthreads();

      if (threadIdx.x == 0) out[blockIdx.x] = sD[0];  // write to global for block
    }

    __device__ void warp_unroll(cuFloatComplex* smem, int tid) {
      float v = reinterpret_cast<float*>(smem)[tid];
      v += __shfl_down_sync(0xFFFFFFFFU, v, 16);
      v += __shfl_down_sync(0xFFFFFFFFU, v, 8);
      v += __shfl_down_sync(0xFFFFFFFFU, v, 4);
      v += __shfl_down_sync(0xFFFFFFFFU, v, 2);
      // Retain two float values, which together represent one complex float number.
      reinterpret_cast<float*>(smem)[tid] = v;
    }
    __global__ void cuReduce_kernel_cf(cuFloatComplex* out, cuFloatComplex* in,
                                       cytnx_uint64 Nelem) {
      __shared__ cuFloatComplex sD[_TNinB_REDUCE_];  // allocate share mem for each thread
      sD[threadIdx.x] = make_cuFloatComplex(0, 0);

      if (blockIdx.x * blockDim.x + threadIdx.x < Nelem) {
        sD[threadIdx.x] = in[blockIdx.x * blockDim.x + threadIdx.x];
      }
      __syncthreads();

      if (blockDim.x >= 1024) {
        if (threadIdx.x < 512) {
          sD[threadIdx.x].x += sD[threadIdx.x + 512].x;
          sD[threadIdx.x].y += sD[threadIdx.x + 512].y;
        }
        __syncthreads();
      }
      if (blockDim.x >= 512) {
        if (threadIdx.x < 256) {
          sD[threadIdx.x].x += sD[threadIdx.x + 256].x;
          sD[threadIdx.x].y += sD[threadIdx.x + 256].y;
        }
        __syncthreads();
      }
      if (blockDim.x >= 256) {
        if (threadIdx.x < 128) {
          sD[threadIdx.x].x += sD[threadIdx.x + 128].x;
          sD[threadIdx.x].y += sD[threadIdx.x + 128].y;
        }
        __syncthreads();
      }
      if (blockDim.x >= 128) {
        if (threadIdx.x < 64) {
          sD[threadIdx.x].x += sD[threadIdx.x + 64].x;
          sD[threadIdx.x].y += sD[threadIdx.x + 64].y;
        }
        __syncthreads();
      }

      if (blockDim.x >= 64) {
        if (threadIdx.x < 32) {
          sD[threadIdx.x].x += sD[threadIdx.x + 32].x;
          sD[threadIdx.x].y += sD[threadIdx.x + 32].y;
        }
        __syncthreads();
      }

      if (blockDim.x >= 32) {
        if (threadIdx.x < 16) {
          sD[threadIdx.x].x += sD[threadIdx.x + 16].x;
          sD[threadIdx.x].y += sD[threadIdx.x + 16].y;
        }
        __syncthreads();
      }

      // A complex float consists of two float values. Up to 32 float values (equivalent to 16
      // complex float numbers) may need to be reduced.
      if (threadIdx.x < 32) warp_unroll(sD, threadIdx.x);
      __syncthreads();

      if (threadIdx.x == 0) out[blockIdx.x] = sD[0];  // write to global for block
    }

    template <class T>
    void swap(T*& a, T*& b) {
      T* tmp = a;
      a = b;
      b = tmp;
    }

    template <class T>
    void cuReduce_gpu_generic(T* out, T* in, const cytnx_uint64& Nelem) {
      cytnx_uint64 Nelems = Nelem;
      cytnx_uint64 NBlocks;

      NBlocks = Nelems / _TNinB_REDUCE_;
      if (Nelems % _TNinB_REDUCE_) NBlocks += 1;

      // alloc mem for each block:
      T* dblk;
      checkCudaErrors(cudaMalloc((void**)&dblk, NBlocks * sizeof(T)));
      if (NBlocks == 1) {
        cuReduce_kernel<<<NBlocks, _TNinB_REDUCE_>>>(out, in, Nelems);
      } else {
        cuReduce_kernel<<<NBlocks, _TNinB_REDUCE_>>>(dblk, in, Nelems);
      }
      Nelems = NBlocks;

      while (Nelems > 1) {
        NBlocks = Nelems / _TNinB_REDUCE_;
        if (Nelems % _TNinB_REDUCE_) NBlocks += 1;

        if (NBlocks == 1) {
          cuReduce_kernel<<<NBlocks, _TNinB_REDUCE_>>>(out, dblk, Nelems);
        } else {
          T* dblk2;
          cudaMalloc((void**)&dblk2, NBlocks * sizeof(T));
          cuReduce_kernel<<<NBlocks, _TNinB_REDUCE_>>>(dblk2, dblk, Nelems);

          swap(dblk2, dblk);
          cudaFree(dblk2);
        }
        Nelems = NBlocks;
      }
      cudaFree(dblk);
    }

    void cuReduce_gpu_d(double* out, double* in, const cytnx_uint64& Nelem) {
      cuReduce_gpu_generic(out, in, Nelem);
    }

    void cuReduce_gpu_f(float* out, float* in, const cytnx_uint64& Nelem) {
      cuReduce_gpu_generic(out, in, Nelem);
    }

    void cuReduce_gpu_i64(cytnx_int64* out, cytnx_int64* in, const cytnx_uint64& Nelem) {
      cuReduce_gpu_generic(out, in, Nelem);
    }
    void cuReduce_gpu_u64(cytnx_uint64* out, cytnx_uint64* in, const cytnx_uint64& Nelem) {
      cuReduce_gpu_generic(out, in, Nelem);
    }

    void cuReduce_gpu_i32(cytnx_int32* out, cytnx_int32* in, const cytnx_uint64& Nelem) {
      cuReduce_gpu_generic(out, in, Nelem);
    }
    void cuReduce_gpu_u32(cytnx_uint32* out, cytnx_uint32* in, const cytnx_uint64& Nelem) {
      cuReduce_gpu_generic(out, in, Nelem);
    }
    void cuReduce_gpu_i16(cytnx_int16* out, cytnx_int16* in, const cytnx_uint64& Nelem) {
      cuReduce_gpu_generic(out, in, Nelem);
    }
    void cuReduce_gpu_u16(cytnx_uint16* out, cytnx_uint16* in, const cytnx_uint64& Nelem) {
      cuReduce_gpu_generic(out, in, Nelem);
    }

    void cuReduce_gpu_cf(cytnx_complex64* out, cytnx_complex64* in, const cytnx_uint64& Nelem) {
      cytnx_uint64 Nelems = Nelem;
      cytnx_uint64 NBlocks;

      NBlocks = Nelems / _TNinB_REDUCE_;
      if (Nelems % _TNinB_REDUCE_) NBlocks += 1;

      // alloc mem for each block:
      cuFloatComplex* dblk;
      cudaMalloc((void**)&dblk, NBlocks * sizeof(cuFloatComplex));

      if (NBlocks == 1) {
        cuReduce_kernel_cf<<<NBlocks, _TNinB_REDUCE_>>>((cuFloatComplex*)out, (cuFloatComplex*)in,
                                                        Nelems);
      } else {
        cuReduce_kernel_cf<<<NBlocks, _TNinB_REDUCE_>>>(dblk, (cuFloatComplex*)in, Nelems);
      }
      Nelems = NBlocks;

      while (Nelems > 1) {
        NBlocks = Nelems / _TNinB_REDUCE_;
        if (Nelems % _TNinB_REDUCE_) NBlocks += 1;

        if (NBlocks == 1) {
          cuReduce_kernel_cf<<<NBlocks, _TNinB_REDUCE_>>>((cuFloatComplex*)out, dblk, Nelems);
        } else {
          cuFloatComplex* dblk2;
          cudaMalloc((void**)&dblk2, NBlocks * sizeof(cuFloatComplex));
          cuReduce_kernel_cf<<<NBlocks, _TNinB_REDUCE_>>>(dblk2, dblk, Nelems);

          swap(dblk2, dblk);
          cudaFree(dblk2);
        }
        Nelems = NBlocks;
      }
      cudaFree(dblk);
    }

    void cuReduce_gpu_cd(cytnx_complex128* out, cytnx_complex128* in, const cytnx_uint64& Nelem) {
      cytnx_uint64 Nelems = Nelem;
      cytnx_uint64 NBlocks;

      NBlocks = Nelems / _TNinB_REDUCE_;
      if (Nelems % _TNinB_REDUCE_) NBlocks += 1;

      // alloc mem for each block:
      cuDoubleComplex* dblk;
      cudaMalloc((void**)&dblk, NBlocks * sizeof(cuDoubleComplex));

      if (NBlocks == 1) {
        cuReduce_kernel_cd<<<NBlocks, _TNinB_REDUCE_>>>((cuDoubleComplex*)out, (cuDoubleComplex*)in,
                                                        Nelems);
      } else {
        cuReduce_kernel_cd<<<NBlocks, _TNinB_REDUCE_>>>(dblk, (cuDoubleComplex*)in, Nelems);
      }
      Nelems = NBlocks;

      while (Nelems > 1) {
        NBlocks = Nelems / _TNinB_REDUCE_;
        if (Nelems % _TNinB_REDUCE_) NBlocks += 1;

        if (NBlocks == 1) {
          cuReduce_kernel_cd<<<NBlocks, _TNinB_REDUCE_>>>((cuDoubleComplex*)out, dblk, Nelems);
        } else {
          cuDoubleComplex* dblk2;
          cudaMalloc((void**)&dblk2, NBlocks * sizeof(cuDoubleComplex));
          cuReduce_kernel_cd<<<NBlocks, _TNinB_REDUCE_>>>(dblk2, dblk, Nelems);

          swap(dblk2, dblk);
          cudaFree(dblk2);
        }
        Nelems = NBlocks;
      }
      cudaFree(dblk);
    }

  }  // namespace utils_internal
}  // namespace cytnx
