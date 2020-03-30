#include <typeinfo>
#include "CyTensor.hpp"
#include "utils/utils_internal_interface.hpp"
#include "linalg.hpp"

using namespace std;

namespace cytnx_extension{
    using namespace cytnx;
    // += 
    template<> CyTensor& CyTensor::operator+=<CyTensor>(const CyTensor &rc){
        *this = cytnx_extension::xlinalg::Add(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator+=<cytnx_complex128>(const cytnx_complex128 &rc){
        *this = cytnx_extension::xlinalg::Add(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator+=<cytnx_complex64>(const cytnx_complex64 &rc){
        *this = cytnx_extension::xlinalg::Add(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator+=<cytnx_double>(const cytnx_double &rc){
        *this = cytnx_extension::xlinalg::Add(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator+=<cytnx_float>(const cytnx_float &rc){
        *this = cytnx_extension::xlinalg::Add(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator+=<cytnx_int64>(const cytnx_int64 &rc){
        *this = cytnx_extension::xlinalg::Add(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator+=<cytnx_uint64>(const cytnx_uint64 &rc){
        *this = cytnx_extension::xlinalg::Add(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator+=<cytnx_int32>(const cytnx_int32 &rc){
        *this = cytnx_extension::xlinalg::Add(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator+=<cytnx_uint32>(const cytnx_uint32 &rc){
        *this = cytnx_extension::xlinalg::Add(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator+=<cytnx_int16>(const cytnx_int16 &rc){
        *this = cytnx_extension::xlinalg::Add(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator+=<cytnx_uint16>(const cytnx_uint16 &rc){
        *this = cytnx_extension::xlinalg::Add(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator+=<cytnx_bool>(const cytnx_bool &rc){
        *this = cytnx_extension::xlinalg::Add(*this,rc);
        return *this;
    }

    // -= 
    template<> CyTensor& CyTensor::operator-=<CyTensor>(const CyTensor &rc){
        *this = cytnx_extension::xlinalg::Sub(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator-=<cytnx_complex128>(const cytnx_complex128 &rc){
        *this = cytnx_extension::xlinalg::Sub(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator-=<cytnx_complex64>(const cytnx_complex64 &rc){
        *this = cytnx_extension::xlinalg::Sub(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator-=<cytnx_double>(const cytnx_double &rc){
        *this = cytnx_extension::xlinalg::Sub(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator-=<cytnx_float>(const cytnx_float &rc){
        *this = cytnx_extension::xlinalg::Sub(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator-=<cytnx_int64>(const cytnx_int64 &rc){
        *this = cytnx_extension::xlinalg::Sub(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator-=<cytnx_uint64>(const cytnx_uint64 &rc){
        *this = cytnx_extension::xlinalg::Sub(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator-=<cytnx_int32>(const cytnx_int32 &rc){
        *this = cytnx_extension::xlinalg::Sub(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator-=<cytnx_uint32>(const cytnx_uint32 &rc){
        *this = cytnx_extension::xlinalg::Sub(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator-=<cytnx_int16>(const cytnx_int16 &rc){
        *this = cytnx_extension::xlinalg::Sub(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator-=<cytnx_uint16>(const cytnx_uint16 &rc){
        *this = cytnx_extension::xlinalg::Sub(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator-=<cytnx_bool>(const cytnx_bool &rc){
        *this = cytnx_extension::xlinalg::Sub(*this,rc);
        return *this;
    }

    // *= 
    template<> CyTensor& CyTensor::operator*=<CyTensor>(const CyTensor &rc){
        *this = cytnx_extension::xlinalg::Mul(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator*=<cytnx_complex128>(const cytnx_complex128 &rc){
        *this = cytnx_extension::xlinalg::Mul(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator*=<cytnx_complex64>(const cytnx_complex64 &rc){
        *this = cytnx_extension::xlinalg::Mul(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator*=<cytnx_double>(const cytnx_double &rc){
        *this = cytnx_extension::xlinalg::Mul(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator*=<cytnx_float>(const cytnx_float &rc){
        *this = cytnx_extension::xlinalg::Mul(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator*=<cytnx_int64>(const cytnx_int64 &rc){
        *this = cytnx_extension::xlinalg::Mul(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator*=<cytnx_uint64>(const cytnx_uint64 &rc){
        *this = cytnx_extension::xlinalg::Mul(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator*=<cytnx_int32>(const cytnx_int32 &rc){
        *this = cytnx_extension::xlinalg::Mul(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator*=<cytnx_uint32>(const cytnx_uint32 &rc){
        *this = cytnx_extension::xlinalg::Mul(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator*=<cytnx_int16>(const cytnx_int16 &rc){
        *this = cytnx_extension::xlinalg::Mul(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator*=<cytnx_uint16>(const cytnx_uint16 &rc){
        *this = cytnx_extension::xlinalg::Mul(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator*=<cytnx_bool>(const cytnx_bool &rc){
        *this = cytnx_extension::xlinalg::Mul(*this,rc);
        return *this;
    }

    // /=
    template<> CyTensor& CyTensor::operator/=<CyTensor>(const CyTensor &rc){
        *this = cytnx_extension::xlinalg::Div(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator/=<cytnx_complex128>(const cytnx_complex128 &rc){
        *this = cytnx_extension::xlinalg::Div(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator/=<cytnx_complex64>(const cytnx_complex64 &rc){
        *this = cytnx_extension::xlinalg::Div(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator/=<cytnx_double>(const cytnx_double &rc){
        *this = cytnx_extension::xlinalg::Div(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator/=<cytnx_float>(const cytnx_float &rc){
        *this = cytnx_extension::xlinalg::Div(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator/=<cytnx_int64>(const cytnx_int64 &rc){
        *this = cytnx_extension::xlinalg::Div(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator/=<cytnx_uint64>(const cytnx_uint64 &rc){
        *this = cytnx_extension::xlinalg::Div(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator/=<cytnx_int32>(const cytnx_int32 &rc){
        *this = cytnx_extension::xlinalg::Div(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator/=<cytnx_uint32>(const cytnx_uint32 &rc){
        *this = cytnx_extension::xlinalg::Div(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator/=<cytnx_int16>(const cytnx_int16 &rc){
        *this = cytnx_extension::xlinalg::Div(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator/=<cytnx_uint16>(const cytnx_uint16 &rc){
        *this = cytnx_extension::xlinalg::Div(*this,rc);
        return *this;
    }
    template<> CyTensor& CyTensor::operator/=<cytnx_bool>(const cytnx_bool &rc){
        *this = cytnx_extension::xlinalg::Div(*this,rc);
        return *this;
    }


}