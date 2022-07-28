#pragma once

#include <cstddef>
#include <vector>

#include "../../constant_pool/cpinfo.h"
#include "../../../types.h"

typedef void* InstructionCallable(void*, void*, std::vector<CpInfo>);


typedef union instruction {
    struct Any {
        Any(u1 _code, bool _reserved) {
            code = _code;
            reserved = _reserved;
        }
        u1 code;
        bool reserved;
        InstructionCallable invoke;

    };
    struct aaload : Any {
        u1 code = static_cast<u1>(0x32);
        bool reserved = false;
        //stackpop arrayref, index
        //stackpush  value
    };
    
    struct aastore : Any {
        u1 code = static_cast<u1>(0x53);
        bool reserved = false;
        //stackpop arrayref, index, value
        //stackpush
    };

    struct aconst_null : Any {
        u1 code = static_cast<u1>(0x01);
        bool reserved = false;
        //stackpop
        //stackpush  null
    };

    struct aload : Any {
        u1 code = static_cast<u1>(0x19);
        bool reserved = false;
        //stackpop
        //stackpush  objectref
    };

    struct aload_0 : Any {
        u1 code = static_cast<u1>(0x2a);
        bool reserved = false;
        //stackpop
        //stackpush  objectref
    };

    struct aload_1 : Any {
        u1 code = static_cast<u1>(0x2b);
        bool reserved = false;
        //stackpop
        //stackpush  objectref
    };

    struct aload_2 : Any {
        u1 code = static_cast<u1>(0x2c);
        bool reserved = false;
        //stackpop
        //stackpush  objectref
    };

    struct aload_3 : Any {
        u1 code = static_cast<u1>(0x2d);
        bool reserved = false;
        //stackpop
        //stackpush  objectref
    };

    struct anewarray : Any {
        u1 code = static_cast<u1>(0xbd);
        bool reserved = false;
        //stackpop count
        //stackpush  arrayref
    };

    struct areturn : Any {
        u1 code = static_cast<u1>(0xb0);
        bool reserved = false;
        //stackpop objectref
        //stackpush  [empty]
    };

    struct arraylength : Any {
        u1 code = static_cast<u1>(0xbe);
        bool reserved = false;
        //stackpop arrayref
        //stackpush  length
    };

    struct astore : Any {
        u1 code = static_cast<u1>(0x3a);
        bool reserved = false;
        //stackpop objectref
        //stackpush
    };

    struct astore_0 : Any {
        u1 code = static_cast<u1>(0x4b);
        bool reserved = false;
        //stackpop objectref
        //stackpush
    };

    struct astore_1 : Any {
        u1 code = static_cast<u1>(0x4c);
        bool reserved = false;
        //stackpop objectref
        //stackpush
    };

    struct astore_2 : Any {
        u1 code = static_cast<u1>(0x4d);
        bool reserved = false;
        //stackpop objectref
        //stackpush
    };

    struct astore_3 : Any {
        u1 code = static_cast<u1>(0x4e);
        bool reserved = false;
        //stackpop objectref
        //stackpush
    };

    struct athrow : Any {
        u1 code = static_cast<u1>(0xbf);
        bool reserved = false;
        //stackpop objectref
        //stackpush  [empty], objectref
    };

    struct baload : Any {
        u1 code = static_cast<u1>(0x33);
        bool reserved = false;
        //stackpop arrayref, index
        //stackpush  value
    };

    struct bastore : Any {
        u1 code = static_cast<u1>(0x54);
        bool reserved = false;
        //stackpop arrayref, index, value
        //stackpush
    };

    struct bipush : Any {
        u1 code = static_cast<u1>(0x10);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct breakpoint : Any {
        u1 code = static_cast<u1>(0xca);
        bool reserved = false;
        //stackpop
        //stackpush undefined
    };

    struct caload : Any {
        u1 code = static_cast<u1>(0x34);
        bool reserved = false;
        //stackpop arrayref, index
        //stackpush  value
    };

    struct castore : Any {
        u1 code = static_cast<u1>(0x55);
        bool reserved = false;
        //stackpop arrayref, index, value
        //stackpush
    };

    struct checkcast : Any {
        u1 code = static_cast<u1>(0xc0);
        bool reserved = false;
        //stackpop objectref
        //stackpush  objectref
    };

    struct d2f : Any {
        u1 code = static_cast<u1>(0x90);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct d2i : Any {
        u1 code = static_cast<u1>(0x8e);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct d2l : Any {
        u1 code = static_cast<u1>(0x8f);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct dadd : Any {
        u1 code = static_cast<u1>(0x63);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct daload : Any {
        u1 code = static_cast<u1>(0x31);
        bool reserved = false;
        //stackpop arrayref, index
        //stackpush  value
    };

    struct dastore : Any {
        u1 code = static_cast<u1>(0x52);
        bool reserved = false;
        //stackpop arrayref, index, value
        //stackpush
    };

    struct dcmpg : Any {
        u1 code = static_cast<u1>(0x98);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct dcmpl : Any {
        u1 code = static_cast<u1>(0x97);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct dconst_0 : Any {
        u1 code = static_cast<u1>(0x0e);
        bool reserved = false;
        //stackpop
        //stackpush  0.0
    };

    struct dconst_1 : Any {
        u1 code = static_cast<u1>(0x0f);
        bool reserved = false;
        //stackpop
        //stackpush  1.0
    };

    struct ddiv : Any {
        u1 code = static_cast<u1>(0x6f);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct dload : Any {
        u1 code = static_cast<u1>(0x18);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct dload_0 : Any {
        u1 code = static_cast<u1>(0x26);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct dload_1 : Any {
        u1 code = static_cast<u1>(0x27);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct dload_2 : Any {
        u1 code = static_cast<u1>(0x28);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct dload_3 : Any {
        u1 code = static_cast<u1>(0x29);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct dmul : Any {
        u1 code = static_cast<u1>(0x6b);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct dneg : Any {
        u1 code = static_cast<u1>(0x77);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct drem : Any {
        u1 code = static_cast<u1>(0x73);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct dreturn : Any {
        u1 code = static_cast<u1>(0xaf);
        bool reserved = false;
        //stackpop value
        //stackpush  [empty]
    };

    struct dstore : Any {
        u1 code = static_cast<u1>(0x39);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct dstore_0 : Any {
        u1 code = static_cast<u1>(0x47);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct dstore_1 : Any {
        u1 code = static_cast<u1>(0x48);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct dstore_2 : Any {
        u1 code = static_cast<u1>(0x49);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct dstore_3 : Any {
        u1 code = static_cast<u1>(0x4a);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct dsub : Any {
        u1 code = static_cast<u1>(0x67);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct dup : Any {
        u1 code = static_cast<u1>(0x59);
        bool reserved = false;
        //stackpop value
        //stackpush  value, value
    };

    struct dup_x1 : Any {
        u1 code = static_cast<u1>(0x5a);
        bool reserved = false;
        //stackpop value2, value1
        //stackpush  value1, value2, value1
    };

    struct dup_x2 : Any {
        u1 code = static_cast<u1>(0x5b);
        bool reserved = false;
        //stackpop value3, value2, value1
        //stackpush  value1, value3, value2, value1
    };

    struct dup2 : Any {
        u1 code = static_cast<u1>(0x5c);
        bool reserved = false;
        //stackpop {value2, value1}
        //stackpush  {value2, value1}, {value2, value1}
    };

    struct dup2_x1 : Any {
        u1 code = static_cast<u1>(0x5d);
        bool reserved = false;
        //stackpop value3, {value2, value1}
        //stackpush  {value2, value1}, value3, {value2, value1}
    };

    struct dup2_x2 : Any {
        u1 code = static_cast<u1>(0x5e);
        bool reserved = false;
        //stackpop {value4, value3}, {value2, value1}
        //stackpush  {value2, value1}, {value4, value3}, {value2, value1}
    };

    struct f2d : Any {
        u1 code = static_cast<u1>(0x8d);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct f2i : Any {
        u1 code = static_cast<u1>(0x8b);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct f2l : Any {
        u1 code = static_cast<u1>(0x8c);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct fadd : Any {
        u1 code = static_cast<u1>(0x62);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct faload : Any {
        u1 code = static_cast<u1>(0x30);
        bool reserved = false;
        //stackpop arrayref, index
        //stackpush  value
    };

    struct fastore : Any {
        u1 code = static_cast<u1>(0x51);
        bool reserved = false;
        //stackpop arrayref, index, value
        //stackpush
    };

    struct fcmpg : Any {
        u1 code = static_cast<u1>(0x96);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct fcmpl : Any {
        u1 code = static_cast<u1>(0x95);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct fconst_0 : Any {
        u1 code = static_cast<u1>(0x0b);
        bool reserved = false;
        //stackpop
        //stackpush  0.0f
    };

    struct fconst_1 : Any {
        u1 code = static_cast<u1>(0x0c);
        bool reserved = false;
        //stackpop
        //stackpush  1.0f
    };

    struct fconst_2 : Any {
        u1 code = static_cast<u1>(0x0d);
        bool reserved = false;
        //stackpop
        //stackpush  2.0f
    };

    struct fdiv : Any {
        u1 code = static_cast<u1>(0x6e);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct fload : Any {
        u1 code = static_cast<u1>(0x17);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct fload_0 : Any {
        u1 code = static_cast<u1>(0x22);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct fload_1 : Any {
        u1 code = static_cast<u1>(0x23);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct fload_2 : Any {
        u1 code = static_cast<u1>(0x24);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct fload_3 : Any {
        u1 code = static_cast<u1>(0x25);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct fmul : Any {
        u1 code = static_cast<u1>(0x6a);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct fneg : Any {
        u1 code = static_cast<u1>(0x76);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct frem : Any {
        u1 code = static_cast<u1>(0x72);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct freturn : Any {
        u1 code = static_cast<u1>(0xae);
        bool reserved = false;
        //stackpop value
        //stackpush  [empty]
    };

    struct fstore : Any {
        u1 code = static_cast<u1>(0x38);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct fstore_0 : Any {
        u1 code = static_cast<u1>(0x43);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct fstore_1 : Any {
        u1 code = static_cast<u1>(0x44);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct fstore_2 : Any {
        u1 code = static_cast<u1>(0x45);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct fstore_3 : Any {
        u1 code = static_cast<u1>(0x46);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct fsub : Any {
        u1 code = static_cast<u1>(0x66);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct getfield : Any {
        u1 code = static_cast<u1>(0xb4);
        bool reserved = false;
        //stackpop objectref
        //stackpush  value
    };

    struct getstatic : Any {
        u1 code = static_cast<u1>(0xb2);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct _goto : Any {
        u1 code = static_cast<u1>(0xa7);
        bool reserved = false;
    };

    struct goto_w : Any {
        u1 code = static_cast<u1>(0xc8);
        bool reserved = false;
    };

    struct i2b : Any {
        u1 code = static_cast<u1>(0x91);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct i2c : Any {
        u1 code = static_cast<u1>(0x92);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct i2d : Any {
        u1 code = static_cast<u1>(0x87);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct i2f : Any {
        u1 code = static_cast<u1>(0x86);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct i2l : Any {
        u1 code = static_cast<u1>(0x85);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct i2s : Any {
        u1 code = static_cast<u1>(0x93);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct iadd : Any {
        u1 code = static_cast<u1>(0x60);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct iaload : Any {
        u1 code = static_cast<u1>(0x2e);
        bool reserved = false;
        //stackpop arrayref, index
        //stackpush  value
    };

    struct iand : Any {
        u1 code = static_cast<u1>(0x7e);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct iastore : Any {
        u1 code = static_cast<u1>(0x4f);
        bool reserved = false;
        //stackpop arrayref, index, value
        //stackpush
    };

    struct iconst_m1 : Any {
        u1 code = static_cast<u1>(0x02);
        bool reserved = false;
        //stackpop
        //stackpush  -1
    };

    struct iconst_0 : Any {
        u1 code = static_cast<u1>(0x03);
        bool reserved = false;
        //stackpop
        //stackpush  0
    };

    struct iconst_1 : Any {
        u1 code = static_cast<u1>(0x04);
        bool reserved = false;
        //stackpop
        //stackpush  1
    };

    struct iconst_2 : Any {
        u1 code = static_cast<u1>(0x05);
        bool reserved = false;
        //stackpop
        //stackpush  2
    };

    struct iconst_3 : Any {
        u1 code = static_cast<u1>(0x06);
        bool reserved = false;
        //stackpop
        //stackpush  3
    };

    struct iconst_4 : Any {
        u1 code = static_cast<u1>(0x07);
        bool reserved = false;
        //stackpop
        //stackpush  4
    };

    struct iconst_5 : Any {
        u1 code = static_cast<u1>(0x08);
        bool reserved = false;
        //stackpop
        //stackpush  5
    };

    struct idiv : Any {
        u1 code = static_cast<u1>(0x6c);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct if_acmpeq : Any {
        u1 code = static_cast<u1>(0xa5);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush
    };

    struct if_acmpne : Any {
        u1 code = static_cast<u1>(0xa6);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush
    };

    struct if_icmpeq : Any {
        u1 code = static_cast<u1>(0x9f);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush
    };

    struct if_icmpge : Any {
        u1 code = static_cast<u1>(0xa2);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush
    };

    struct if_icmpgt : Any {
        u1 code = static_cast<u1>(0xa3);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush
    };

    struct if_icmple : Any {
        u1 code = static_cast<u1>(0xa4);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush
    };

    struct if_icmplt : Any {
        u1 code = static_cast<u1>(0xa1);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush
    };

    struct if_icmpne : Any {
        u1 code = static_cast<u1>(0xa0);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush
    };

    struct ifeq : Any {
        u1 code = static_cast<u1>(0x99);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct ifge : Any {
        u1 code = static_cast<u1>(0x9c);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct ifgt : Any {
        u1 code = static_cast<u1>(0x9d);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct ifle : Any {
        u1 code = static_cast<u1>(0x9e);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct iflt : Any {
        u1 code = static_cast<u1>(0x9b);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct ifne : Any {
        u1 code = static_cast<u1>(0x9a);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct ifnonnull : Any {
        u1 code = static_cast<u1>(0xc7);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct ifnull : Any {
        u1 code = static_cast<u1>(0xc6);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct iinc : Any {
        u1 code = static_cast<u1>(0x84);
        bool reserved = false;
        //stackpop [No change]
        //stackpush undefined
    };

    struct iload : Any {
        u1 code = static_cast<u1>(0x15);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct iload_0 : Any {
        u1 code = static_cast<u1>(0x1a);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct iload_1 : Any {
        u1 code = static_cast<u1>(0x1b);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct iload_2 : Any {
        u1 code = static_cast<u1>(0x1c);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct iload_3 : Any {
        u1 code = static_cast<u1>(0x1d);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct impdep1 : Any {
        u1 code = static_cast<u1>(0xfe);
        bool reserved = false;
        //stackpop
        //stackpush undefined
    };

    struct impdep2 : Any {
        u1 code = static_cast<u1>(0xff);
        bool reserved = false;
        //stackpop
        //stackpush undefined
    };

    struct imul : Any {
        u1 code = static_cast<u1>(0x68);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct ineg : Any {
        u1 code = static_cast<u1>(0x74);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct instanceof : Any {
        u1 code = static_cast<u1>(0xc1);
        bool reserved = false;
        //stackpop objectref
        //stackpush  result
    };

    struct invokedynamic : Any {
        u1 code = static_cast<u1>(0xba);
        bool reserved = false;
        //stackpop [arg1, arg2, ...]
        //stackpush  result
    };

    struct invokeinterface : Any {
        u1 code = static_cast<u1>(0xb9);
        bool reserved = false;
        //stackpop objectref, [arg1, arg2, ...]
        //stackpush  result
    };

    struct invokespecial : Any {
        u1 code = static_cast<u1>(0xb7);
        bool reserved = false;
        //stackpop objectref, [arg1, arg2, ...]
        //stackpush  result
    };

    struct invokestatic : Any {
        u1 code = static_cast<u1>(0xb8);
        bool reserved = false;
        //stackpop [arg1, arg2, ...]
        //stackpush  result
    };

    struct invokevirtual : Any {
        u1 code = static_cast<u1>(0xb6);
        bool reserved = false;
        //stackpop objectref, [arg1, arg2, ...]
        //stackpush  result
    };

    struct ior : Any {
        u1 code = static_cast<u1>(0x80);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct irem : Any {
        u1 code = static_cast<u1>(0x70);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct ireturn : Any {
        u1 code = static_cast<u1>(0xac);
        bool reserved = false;
        //stackpop value
        //stackpush  [empty]
    };

    struct ishl : Any {
        u1 code = static_cast<u1>(0x78);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct ishr : Any {
        u1 code = static_cast<u1>(0x7a);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct istore : Any {
        u1 code = static_cast<u1>(0x36);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct istore_0 : Any {
        u1 code = static_cast<u1>(0x3b);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct istore_1 : Any {
        u1 code = static_cast<u1>(0x3c);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct istore_2 : Any {
        u1 code = static_cast<u1>(0x3d);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct istore_3 : Any {
        u1 code = static_cast<u1>(0x3e);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct isub : Any {
        u1 code = static_cast<u1>(0x64);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct iushr : Any {
        u1 code = static_cast<u1>(0x7c);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct ixor : Any {
        u1 code = static_cast<u1>(0x82);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct jsr : Any {
        u1 code = static_cast<u1>(0xa8);
        bool reserved = false;
        //stackpop
        //stackpush  address
    };

    struct jsr_w : Any {
        u1 code = static_cast<u1>(0xc9);
        bool reserved = false;
        //stackpop
        //stackpush  address
    };

    struct l2d : Any {
        u1 code = static_cast<u1>(0x8a);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct l2f : Any {
        u1 code = static_cast<u1>(0x89);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct l2i : Any {
        u1 code = static_cast<u1>(0x88);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct ladd : Any {
        u1 code = static_cast<u1>(0x61);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct laload : Any {
        u1 code = static_cast<u1>(0x2f);
        bool reserved = false;
        //stackpop arrayref, index
        //stackpush  value
    };

    struct land : Any {
        u1 code = static_cast<u1>(0x7f);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct lastore : Any {
        u1 code = static_cast<u1>(0x50);
        bool reserved = false;
        //stackpop arrayref, index, value
        //stackpush
    };

    struct lcmp : Any {
        u1 code = static_cast<u1>(0x94);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct lconst_0 : Any {
        u1 code = static_cast<u1>(0x09);
        bool reserved = false;
        //stackpop
        //stackpush  0L
    };

    struct lconst_1 : Any {
        u1 code = static_cast<u1>(0x0a);
        bool reserved = false;
        //stackpop
        //stackpush  1L
    };

    struct ldc : Any {
        u1 code = static_cast<u1>(0x12);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct ldc_w : Any {
        u1 code = static_cast<u1>(0x13);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct ldc2_w : Any {
        u1 code = static_cast<u1>(0x14);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct ldiv : Any {
        u1 code = static_cast<u1>(0x6d);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct lload : Any {
        u1 code = static_cast<u1>(0x16);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct lload_0 : Any {
        u1 code = static_cast<u1>(0x1e);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct lload_1 : Any {
        u1 code = static_cast<u1>(0x1f);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct lload_2 : Any {
        u1 code = static_cast<u1>(0x20);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct lload_3 : Any {
        u1 code = static_cast<u1>(0x21);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct lmul : Any {
        u1 code = static_cast<u1>(0x69);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct lneg : Any {
        u1 code = static_cast<u1>(0x75);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct lookupswitch : Any {
        u1 code = static_cast<u1>(0xab);
        bool reserved = false;
        //stackpop key
        //stackpush
    };

    struct lor : Any {
        u1 code = static_cast<u1>(0x81);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct lrem : Any {
        u1 code = static_cast<u1>(0x71);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct lreturn : Any {
        u1 code = static_cast<u1>(0xad);
        bool reserved = false;
        //stackpop value
        //stackpush  [empty]
    };

    struct lshl : Any {
        u1 code = static_cast<u1>(0x79);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct lshr : Any {
        u1 code = static_cast<u1>(0x7b);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct lstore : Any {
        u1 code = static_cast<u1>(0x37);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct lstore_0 : Any {
        u1 code = static_cast<u1>(0x3f);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct lstore_1 : Any {
        u1 code = static_cast<u1>(0x40);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct lstore_2 : Any {
        u1 code = static_cast<u1>(0x41);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct lstore_3 : Any {
        u1 code = static_cast<u1>(0x42);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct lsub : Any {
        u1 code = static_cast<u1>(0x65);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct lushr : Any {
        u1 code = static_cast<u1>(0x7d);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct lxor : Any {
        u1 code = static_cast<u1>(0x83);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct monitorenter : Any {
        u1 code = static_cast<u1>(0xc2);
        bool reserved = false;
        //stackpop objectref
        //stackpush
    };

    struct monitorexit : Any {
        u1 code = static_cast<u1>(0xc3);
        bool reserved = false;
        //stackpop objectref
        //stackpush
    };

    struct multianewarray : Any {
        u1 code = static_cast<u1>(0xc5);
        bool reserved = false;
        //stackpop count1, [count2,...]
        //stackpush  arrayref
    };

    struct _new : Any {
        u1 code = static_cast<u1>(0xbb);
        bool reserved = false;
        //stackpop
        //stackpush  objectref
    };

    struct newarray : Any {
        u1 code = static_cast<u1>(0xbc);
        bool reserved = false;
        //stackpop count
        //stackpush  arrayref
    };

    struct nop : Any {
        u1 code = static_cast<u1>(0x00);
        bool reserved = false;
        //stackpop [No change]
        //stackpush undefined
    };

    struct pop : Any {
        u1 code = static_cast<u1>(0x57);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct pop2 : Any {
        u1 code = static_cast<u1>(0x58);
        bool reserved = false;
        //stackpop {value2, value1}
        //stackpush
    };

    struct putfield : Any {
        u1 code = static_cast<u1>(0xb5);
        bool reserved = false;
        //stackpop objectref, value
        //stackpush
    };

    struct putstatic : Any {
        u1 code = static_cast<u1>(0xb3);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct ret : Any {
        u1 code = static_cast<u1>(0xa9);
        bool reserved = false;
        //stackpop [No change]
        //stackpush undefined
    };

    struct _return : Any {
        u1 code = static_cast<u1>(0xb1);
        bool reserved = false;
        //stackpop
        //stackpush  [empty]
    };

    struct saload : Any {
        u1 code = static_cast<u1>(0x35);
        bool reserved = false;
        //stackpop arrayref, index
        //stackpush  value
    };

    struct sastore : Any {
        u1 code = static_cast<u1>(0x56);
        bool reserved = false;
        //stackpop arrayref, index, value
        //stackpush
    };

    struct sipush : Any {
        u1 code = static_cast<u1>(0x11);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct swap : Any {
        u1 code = static_cast<u1>(0x5f);
        bool reserved = false;
        //stackpop value2, value1
        //stackpush  value1, value2
    };

    struct tableswitch : Any {
        u1 code = static_cast<u1>(0xaa);
        bool reserved = false;
        //stackpop index
        //stackpush
    };

    struct wide : Any {
        u1 code = static_cast<u1>(0xc4);
        bool reserved = false;
        //stackpop [same as for corresponding instructions]
        //stackpush undefined
    };
} instruction;
