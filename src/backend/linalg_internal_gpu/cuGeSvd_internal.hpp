#ifndef CYTNX_BACKEND_LINALG_INTERNAL_GPU_CUGESVD_INTERNAL_H_
#define CYTNX_BACKEND_LINALG_INTERNAL_GPU_CUGESVD_INTERNAL_H_

#include <assert.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include "backend/Storage.hpp"
#include "Type.hpp"
#include "cytnx_error.hpp"
#include "backend/lapack_wrapper.hpp"
// #include "../linalg_internal_interface.hpp"
namespace cytnx {

  namespace linalg_internal {

    /// cuSvd
    void cuGeSvd_internal_cd(const boost::intrusive_ptr<Storage_base> &in,
                             boost::intrusive_ptr<Storage_base> &U,
                             boost::intrusive_ptr<Storage_base> &vT,
                             boost::intrusive_ptr<Storage_base> &s, const cytnx_int64 &M,
                             const cytnx_int64 &N);
    void cuGeSvd_internal_cf(const boost::intrusive_ptr<Storage_base> &in,
                             boost::intrusive_ptr<Storage_base> &U,
                             boost::intrusive_ptr<Storage_base> &vT,
                             boost::intrusive_ptr<Storage_base> &s, const cytnx_int64 &M,
                             const cytnx_int64 &N);
    void cuGeSvd_internal_d(const boost::intrusive_ptr<Storage_base> &in,
                            boost::intrusive_ptr<Storage_base> &U,
                            boost::intrusive_ptr<Storage_base> &vT,
                            boost::intrusive_ptr<Storage_base> &s, const cytnx_int64 &M,
                            const cytnx_int64 &N);
    void cuGeSvd_internal_f(const boost::intrusive_ptr<Storage_base> &in,
                            boost::intrusive_ptr<Storage_base> &U,
                            boost::intrusive_ptr<Storage_base> &vT,
                            boost::intrusive_ptr<Storage_base> &s, const cytnx_int64 &M,
                            const cytnx_int64 &N);

  }  // namespace linalg_internal
}  // namespace cytnx

#endif  // CYTNX_BACKEND_LINALG_INTERNAL_GPU_CUGESVD_INTERNAL_H_
