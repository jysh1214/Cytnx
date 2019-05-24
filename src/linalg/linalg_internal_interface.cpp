#include "linalg/linalg_internal_interface.hpp"

using namespace std;

namespace tor10{
    namespace linalg_internal{


        linalg_internal_interface lii;

        linalg_internal_interface::linalg_internal_interface(){
            Ari_ii = vector<vector<Arithmicfunc_oii> >(N_Type,vector<Arithmicfunc_oii>(N_Type,NULL));

            Ari_ii[tor10type.ComplexDouble][tor10type.ComplexDouble] = Arithmic_internal_cdtcd;
            Ari_ii[tor10type.ComplexDouble][tor10type.ComplexFloat ] = Arithmic_internal_cdtcf;
            Ari_ii[tor10type.ComplexDouble][tor10type.Double       ] = Arithmic_internal_cdtd;
            Ari_ii[tor10type.ComplexDouble][tor10type.Float        ] = Arithmic_internal_cdtf;
            Ari_ii[tor10type.ComplexDouble][tor10type.Int64        ] = Arithmic_internal_cdti64;
            Ari_ii[tor10type.ComplexDouble][tor10type.Uint64       ] = Arithmic_internal_cdtu64;
            Ari_ii[tor10type.ComplexDouble][tor10type.Int32        ] = Arithmic_internal_cdti32;
            Ari_ii[tor10type.ComplexDouble][tor10type.Uint32       ] = Arithmic_internal_cdtu32;
            
            Ari_ii[tor10type.ComplexFloat][tor10type.ComplexDouble] = Arithmic_internal_cftcd;
            Ari_ii[tor10type.ComplexFloat][tor10type.ComplexFloat ] = Arithmic_internal_cftcf;
            Ari_ii[tor10type.ComplexFloat][tor10type.Double       ] = Arithmic_internal_cftd;
            Ari_ii[tor10type.ComplexFloat][tor10type.Float        ] = Arithmic_internal_cftf;
            Ari_ii[tor10type.ComplexFloat][tor10type.Int64        ] = Arithmic_internal_cfti64;
            Ari_ii[tor10type.ComplexFloat][tor10type.Uint64       ] = Arithmic_internal_cftu64;
            Ari_ii[tor10type.ComplexFloat][tor10type.Int32        ] = Arithmic_internal_cfti32;
            Ari_ii[tor10type.ComplexFloat][tor10type.Uint32       ] = Arithmic_internal_cftu32;
            
            Ari_ii[tor10type.Double][tor10type.ComplexDouble] = Arithmic_internal_dtcd;
            Ari_ii[tor10type.Double][tor10type.ComplexFloat ] = Arithmic_internal_dtcf;
            Ari_ii[tor10type.Double][tor10type.Double       ] = Arithmic_internal_dtd;
            Ari_ii[tor10type.Double][tor10type.Float        ] = Arithmic_internal_dtf;
            Ari_ii[tor10type.Double][tor10type.Int64        ] = Arithmic_internal_dti64;
            Ari_ii[tor10type.Double][tor10type.Uint64       ] = Arithmic_internal_dtu64;
            Ari_ii[tor10type.Double][tor10type.Int32        ] = Arithmic_internal_dti32;
            Ari_ii[tor10type.Double][tor10type.Uint32       ] = Arithmic_internal_dtu32;
            
            Ari_ii[tor10type.Float][tor10type.ComplexDouble] = Arithmic_internal_ftcd;
            Ari_ii[tor10type.Float][tor10type.ComplexFloat ] = Arithmic_internal_ftcf;
            Ari_ii[tor10type.Float][tor10type.Double       ] = Arithmic_internal_ftd;
            Ari_ii[tor10type.Float][tor10type.Float        ] = Arithmic_internal_ftf;
            Ari_ii[tor10type.Float][tor10type.Int64        ] = Arithmic_internal_fti64;
            Ari_ii[tor10type.Float][tor10type.Uint64       ] = Arithmic_internal_ftu64;
            Ari_ii[tor10type.Float][tor10type.Int32        ] = Arithmic_internal_fti32;
            Ari_ii[tor10type.Float][tor10type.Uint32       ] = Arithmic_internal_ftu32;
            
            Ari_ii[tor10type.Int64][tor10type.ComplexDouble] = Arithmic_internal_i64tcd;
            Ari_ii[tor10type.Int64][tor10type.ComplexFloat ] = Arithmic_internal_i64tcf;
            Ari_ii[tor10type.Int64][tor10type.Double       ] = Arithmic_internal_i64td;
            Ari_ii[tor10type.Int64][tor10type.Float        ] = Arithmic_internal_i64tf;
            Ari_ii[tor10type.Int64][tor10type.Int64        ] = Arithmic_internal_i64ti64;
            Ari_ii[tor10type.Int64][tor10type.Uint64       ] = Arithmic_internal_i64tu64;
            Ari_ii[tor10type.Int64][tor10type.Int32        ] = Arithmic_internal_i64ti32;
            Ari_ii[tor10type.Int64][tor10type.Uint32       ] = Arithmic_internal_i64tu32;
            
            Ari_ii[tor10type.Uint64][tor10type.ComplexDouble] = Arithmic_internal_u64tcd;
            Ari_ii[tor10type.Uint64][tor10type.ComplexFloat ] = Arithmic_internal_u64tcf;
            Ari_ii[tor10type.Uint64][tor10type.Double       ] = Arithmic_internal_u64td;
            Ari_ii[tor10type.Uint64][tor10type.Float        ] = Arithmic_internal_u64tf;
            Ari_ii[tor10type.Uint64][tor10type.Int64        ] = Arithmic_internal_u64ti64;
            Ari_ii[tor10type.Uint64][tor10type.Uint64       ] = Arithmic_internal_u64tu64;
            Ari_ii[tor10type.Uint64][tor10type.Int32        ] = Arithmic_internal_u64ti32;
            Ari_ii[tor10type.Uint64][tor10type.Uint32       ] = Arithmic_internal_u64tu32;
            
            Ari_ii[tor10type.Int32][tor10type.ComplexDouble] = Arithmic_internal_i32tcd;
            Ari_ii[tor10type.Int32][tor10type.ComplexFloat ] = Arithmic_internal_i32tcf;
            Ari_ii[tor10type.Int32][tor10type.Double       ] = Arithmic_internal_i32td;
            Ari_ii[tor10type.Int32][tor10type.Float        ] = Arithmic_internal_i32tf;
            Ari_ii[tor10type.Int32][tor10type.Int64        ] = Arithmic_internal_i32ti64;
            Ari_ii[tor10type.Int32][tor10type.Uint64       ] = Arithmic_internal_i32tu64;
            Ari_ii[tor10type.Int32][tor10type.Int32        ] = Arithmic_internal_i32ti32;
            Ari_ii[tor10type.Int32][tor10type.Uint32       ] = Arithmic_internal_i32tu32;
            
            Ari_ii[tor10type.Uint32][tor10type.ComplexDouble] = Arithmic_internal_u32tcd;
            Ari_ii[tor10type.Uint32][tor10type.ComplexFloat ] = Arithmic_internal_u32tcf;
            Ari_ii[tor10type.Uint32][tor10type.Double       ] = Arithmic_internal_u32td;
            Ari_ii[tor10type.Uint32][tor10type.Float        ] = Arithmic_internal_u32tf;
            Ari_ii[tor10type.Uint32][tor10type.Int64        ] = Arithmic_internal_u32ti64;
            Ari_ii[tor10type.Uint32][tor10type.Uint64       ] = Arithmic_internal_u32tu64;
            Ari_ii[tor10type.Uint32][tor10type.Int32        ] = Arithmic_internal_u32ti32;
            Ari_ii[tor10type.Uint32][tor10type.Uint32       ] = Arithmic_internal_u32tu32;

            //=====================
            Svd_ii = vector<Svdfunc_oii>(5);

            Svd_ii[tor10type.ComplexDouble] = Svd_internal_cd;
            Svd_ii[tor10type.ComplexFloat ] = Svd_internal_cf;
            Svd_ii[tor10type.Double       ] = Svd_internal_d;
            Svd_ii[tor10type.Float        ] = Svd_internal_f;



            #ifdef UNI_GPU
                cuAri_ii = vector<vector<Arithmicfunc_oii> >(N_Type,vector<Arithmicfunc_oii>(N_Type));

                cuAri_ii[tor10type.ComplexDouble][tor10type.ComplexDouble] = cuArithmic_internal_cdtcd;
                cuAri_ii[tor10type.ComplexDouble][tor10type.ComplexFloat ] = cuArithmic_internal_cdtcf;
                cuAri_ii[tor10type.ComplexDouble][tor10type.Double       ] = cuArithmic_internal_cdtd;
                cuAri_ii[tor10type.ComplexDouble][tor10type.Float        ] = cuArithmic_internal_cdtf;
                cuAri_ii[tor10type.ComplexDouble][tor10type.Int64        ] = cuArithmic_internal_cdti64;
                cuAri_ii[tor10type.ComplexDouble][tor10type.Uint64       ] = cuArithmic_internal_cdtu64;
                cuAri_ii[tor10type.ComplexDouble][tor10type.Int32        ] = cuArithmic_internal_cdti32;
                cuAri_ii[tor10type.ComplexDouble][tor10type.Uint32       ] = cuArithmic_internal_cdtu32;
                
                cuAri_ii[tor10type.ComplexFloat][tor10type.ComplexDouble] = cuArithmic_internal_cftcd;
                cuAri_ii[tor10type.ComplexFloat][tor10type.ComplexFloat ] = cuArithmic_internal_cftcf;
                cuAri_ii[tor10type.ComplexFloat][tor10type.Double       ] = cuArithmic_internal_cftd;
                cuAri_ii[tor10type.ComplexFloat][tor10type.Float        ] = cuArithmic_internal_cftf;
                cuAri_ii[tor10type.ComplexFloat][tor10type.Int64        ] = cuArithmic_internal_cfti64;
                cuAri_ii[tor10type.ComplexFloat][tor10type.Uint64       ] = cuArithmic_internal_cftu64;
                cuAri_ii[tor10type.ComplexFloat][tor10type.Int32        ] = cuArithmic_internal_cfti32;
                cuAri_ii[tor10type.ComplexFloat][tor10type.Uint32       ] = cuArithmic_internal_cftu32;
                
                cuAri_ii[tor10type.Double][tor10type.ComplexDouble] = cuArithmic_internal_dtcd;
                cuAri_ii[tor10type.Double][tor10type.ComplexFloat ] = cuArithmic_internal_dtcf;
                cuAri_ii[tor10type.Double][tor10type.Double       ] = cuArithmic_internal_dtd;
                cuAri_ii[tor10type.Double][tor10type.Float        ] = cuArithmic_internal_dtf;
                cuAri_ii[tor10type.Double][tor10type.Int64        ] = cuArithmic_internal_dti64;
                cuAri_ii[tor10type.Double][tor10type.Uint64       ] = cuArithmic_internal_dtu64;
                cuAri_ii[tor10type.Double][tor10type.Int32        ] = cuArithmic_internal_dti32;
                cuAri_ii[tor10type.Double][tor10type.Uint32       ] = cuArithmic_internal_dtu32;
                
                cuAri_ii[tor10type.Float][tor10type.ComplexDouble] = cuArithmic_internal_ftcd;
                cuAri_ii[tor10type.Float][tor10type.ComplexFloat ] = cuArithmic_internal_ftcf;
                cuAri_ii[tor10type.Float][tor10type.Double       ] = cuArithmic_internal_ftd;
                cuAri_ii[tor10type.Float][tor10type.Float        ] = cuArithmic_internal_ftf;
                cuAri_ii[tor10type.Float][tor10type.Int64        ] = cuArithmic_internal_fti64;
                cuAri_ii[tor10type.Float][tor10type.Uint64       ] = cuArithmic_internal_ftu64;
                cuAri_ii[tor10type.Float][tor10type.Int32        ] = cuArithmic_internal_fti32;
                cuAri_ii[tor10type.Float][tor10type.Uint32       ] = cuArithmic_internal_ftu32;
                
                cuAri_ii[tor10type.Int64][tor10type.ComplexDouble] = cuArithmic_internal_i64tcd;
                cuAri_ii[tor10type.Int64][tor10type.ComplexFloat ] = cuArithmic_internal_i64tcf;
                cuAri_ii[tor10type.Int64][tor10type.Double       ] = cuArithmic_internal_i64td;
                cuAri_ii[tor10type.Int64][tor10type.Float        ] = cuArithmic_internal_i64tf;
                cuAri_ii[tor10type.Int64][tor10type.Int64        ] = cuArithmic_internal_i64ti64;
                cuAri_ii[tor10type.Int64][tor10type.Uint64       ] = cuArithmic_internal_i64tu64;
                cuAri_ii[tor10type.Int64][tor10type.Int32        ] = cuArithmic_internal_i64ti32;
                cuAri_ii[tor10type.Int64][tor10type.Uint32       ] = cuArithmic_internal_i64tu32;
                
                cuAri_ii[tor10type.Uint64][tor10type.ComplexDouble] = cuArithmic_internal_u64tcd;
                cuAri_ii[tor10type.Uint64][tor10type.ComplexFloat ] = cuArithmic_internal_u64tcf;
                cuAri_ii[tor10type.Uint64][tor10type.Double       ] = cuArithmic_internal_u64td;
                cuAri_ii[tor10type.Uint64][tor10type.Float        ] = cuArithmic_internal_u64tf;
                cuAri_ii[tor10type.Uint64][tor10type.Int64        ] = cuArithmic_internal_u64ti64;
                cuAri_ii[tor10type.Uint64][tor10type.Uint64       ] = cuArithmic_internal_u64tu64;
                cuAri_ii[tor10type.Uint64][tor10type.Int32        ] = cuArithmic_internal_u64ti32;
                cuAri_ii[tor10type.Uint64][tor10type.Uint32       ] = cuArithmic_internal_u64tu32;
                
                cuAri_ii[tor10type.Int32][tor10type.ComplexDouble] = cuArithmic_internal_i32tcd;
                cuAri_ii[tor10type.Int32][tor10type.ComplexFloat ] = cuArithmic_internal_i32tcf;
                cuAri_ii[tor10type.Int32][tor10type.Double       ] = cuArithmic_internal_i32td;
                cuAri_ii[tor10type.Int32][tor10type.Float        ] = cuArithmic_internal_i32tf;
                cuAri_ii[tor10type.Int32][tor10type.Int64        ] = cuArithmic_internal_i32ti64;
                cuAri_ii[tor10type.Int32][tor10type.Uint64       ] = cuArithmic_internal_i32tu64;
                cuAri_ii[tor10type.Int32][tor10type.Int32        ] = cuArithmic_internal_i32ti32;
                cuAri_ii[tor10type.Int32][tor10type.Uint32       ] = cuArithmic_internal_i32tu32;
                
                cuAri_ii[tor10type.Uint32][tor10type.ComplexDouble] = cuArithmic_internal_u32tcd;
                cuAri_ii[tor10type.Uint32][tor10type.ComplexFloat ] = cuArithmic_internal_u32tcf;
                cuAri_ii[tor10type.Uint32][tor10type.Double       ] = cuArithmic_internal_u32td;
                cuAri_ii[tor10type.Uint32][tor10type.Float        ] = cuArithmic_internal_u32tf;
                cuAri_ii[tor10type.Uint32][tor10type.Int64        ] = cuArithmic_internal_u32ti64;
                cuAri_ii[tor10type.Uint32][tor10type.Uint64       ] = cuArithmic_internal_u32tu64;
                cuAri_ii[tor10type.Uint32][tor10type.Int32        ] = cuArithmic_internal_u32ti32;
                cuAri_ii[tor10type.Uint32][tor10type.Uint32       ] = cuArithmic_internal_u32tu32;
            
                // Svd
                cuSvd_ii = vector<Svdfunc_oii>(5);

                cuSvd_ii[tor10type.ComplexDouble] = cuSvd_internal_cd;
                cuSvd_ii[tor10type.ComplexFloat ] = cuSvd_internal_cf;
                cuSvd_ii[tor10type.Double       ] = cuSvd_internal_d;
                cuSvd_ii[tor10type.Float        ] = cuSvd_internal_f;

            #endif
        }

    }
}
