#include "Conj_inplace_internal.hpp"
#include "cytnx_error.hpp"
#include "backend/lapack_wrapper.hpp"

namespace cytnx {
  namespace linalg_internal {

    void Conj_inplace_internal_cf(boost::intrusive_ptr<Storage_base> &ten,
                                  const cytnx_uint64 &Nelem) {
      cytnx_complex64 *tmp = (cytnx_complex64 *)ten->data();

      for (cytnx_uint64 n = 0; n < Nelem; n++) {
        tmp[n].imag(-tmp[n].imag());
      }
    }

    void Conj_inplace_internal_cd(boost::intrusive_ptr<Storage_base> &ten,
                                  const cytnx_uint64 &Nelem) {
      cytnx_complex128 *tmp = (cytnx_complex128 *)ten->data();

      for (cytnx_uint64 n = 0; n < Nelem; n++) {
        tmp[n].imag(-tmp[n].imag());
      }
    }

  }  // namespace linalg_internal

}  // namespace cytnx
