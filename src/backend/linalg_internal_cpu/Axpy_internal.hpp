#ifndef CYTNX_BACKEND_LINALG_INTERNAL_CPU_AXPY_INTERNAL_H_
#define CYTNX_BACKEND_LINALG_INTERNAL_CPU_AXPY_INTERNAL_H_

#include <assert.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include "backend/Storage.hpp"
#include "Type.hpp"
#include "backend/Scalar.hpp"

namespace cytnx {

  namespace linalg_internal {

    /// Axpy
    void Axpy_internal_cd(const boost::intrusive_ptr<Storage_base> &x,
                          boost::intrusive_ptr<Storage_base> &y, const Scalar &a);
    void Axpy_internal_cf(const boost::intrusive_ptr<Storage_base> &x,
                          boost::intrusive_ptr<Storage_base> &y, const Scalar &a);

    void Axpy_internal_d(const boost::intrusive_ptr<Storage_base> &x,
                         boost::intrusive_ptr<Storage_base> &y, const Scalar &a);

    void Axpy_internal_f(const boost::intrusive_ptr<Storage_base> &x,
                         boost::intrusive_ptr<Storage_base> &y, const Scalar &a);

  }  // namespace linalg_internal
}  // namespace cytnx

#endif  // CYTNX_BACKEND_LINALG_INTERNAL_CPU_AXPY_INTERNAL_H_
