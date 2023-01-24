from cy_type import *

for t1,t1name in enumerate(DTYPES_FULL):
    for t2,t2name in enumerate(DTYPES_FULL):
        output_typeid = typeid_promote(t1,t2)
        output_type = DTYPES_FULL[output_typeid]
        print("\
        // This function is generated by python script\n\
        void cuOuter_internal_"+DTYPES_SIMPLE[t1]+"t"+DTYPES_SIMPLE[t2]+"(boost::intrusive_ptr<Storage_base> &out,\n\
                                    const boost::intrusive_ptr<Storage_base> &Lin,\n\
                                    const boost::intrusive_ptr<Storage_base> &Rin, const cytnx_uint64 &j1,\n\
                                    const cytnx_uint64 &j2) {\n\
            cuOuter_general<"+output_type+","+t1name+","+t2name+">(out, Lin, Rin, j1,j2);\n\
        }\n")
