#pragma once
//
// created by aenri someday
//

#include <cstddef>
#include <vector>

#include "../../constant_pool/cpinfo.h"

using std::byte

typedef void* InstructionCallable(void*, void*, std::vector<CpInfo>);


typedef union instruction {
    struct Any {
        Any(byte _code, bool _reserved) {
            code = _code;
            reserved = _reserved;
        }
        byte code;
        bool reserved;
        InstructionCallable invoke;

    };
    struct aaload : Any {
        byte code = static_cast<byte>(0x32);
        bool reserved = false;
        //stackpop arrayref, index
        //stackpush  value
    };

    struct aastore : Any {
        byte code = static_cast<byte>(0x53);
        bool reserved = false;
        //stackpop arrayref, index, value
        //stackpush
    };

    struct aconst_null : Any {
        byte code = static_cast<byte>(0x01);
        bool reserved = false;
        //stackpop
        //stackpush  null
    };

    struct aload : Any {
        byte code = static_cast<byte>(0x19);
        bool reserved = false;
        //stackpop
        //stackpush  objectref
    };

    struct aload_0 : Any {
        byte code = static_cast<byte>(0x2a);
        bool reserved = false;
        //stackpop
        //stackpush  objectref
    };

    struct aload_1 : Any {
        byte code = static_cast<byte>(0x2b);
        bool reserved = false;
        //stackpop
        //stackpush  objectref
    };

    struct aload_2 : Any {
        byte code = static_cast<byte>(0x2c);
        bool reserved = false;
        //stackpop
        //stackpush  objectref
    };

    struct aload_3 : Any {
        byte code = static_cast<byte>(0x2d);
        bool reserved = false;
        //stackpop
        //stackpush  objectref
    };

    struct anewarray : Any {
        byte code = static_cast<byte>(0xbd);
        bool reserved = false;
        //stackpop count
        //stackpush  arrayref
    };

    struct areturn : Any {
        byte code = static_cast<byte>(0xb0);
        bool reserved = false;
        //stackpop objectref
        //stackpush  [empty]
    };

    struct arraylength : Any {
        byte code = static_cast<byte>(0xbe);
        bool reserved = false;
        //stackpop arrayref
        //stackpush  length
    };

    struct astore : Any {
        byte code = static_cast<byte>(0x3a);
        bool reserved = false;
        //stackpop objectref
        //stackpush
    };

    struct astore_0 : Any {
        byte code = static_cast<byte>(0x4b);
        bool reserved = false;
        //stackpop objectref
        //stackpush
    };

    struct astore_1 : Any {
        byte code = static_cast<byte>(0x4c);
        bool reserved = false;
        //stackpop objectref
        //stackpush
    };

    struct astore_2 : Any {
        byte code = static_cast<byte>(0x4d);
        bool reserved = false;
        //stackpop objectref
        //stackpush
    };

    struct astore_3 : Any {
        byte code = static_cast<byte>(0x4e);
        bool reserved = false;
        //stackpop objectref
        //stackpush
    };

    struct athrow : Any {
        byte code = static_cast<byte>(0xbf);
        bool reserved = false;
        //stackpop objectref
        //stackpush  [empty], objectref
    };

    struct baload : Any {
        byte code = static_cast<byte>(0x33);
        bool reserved = false;
        //stackpop arrayref, index
        //stackpush  value
    };

    struct bastore : Any {
        byte code = static_cast<byte>(0x54);
        bool reserved = false;
        //stackpop arrayref, index, value
        //stackpush
    };

    struct bipush : Any {
        byte code = static_cast<byte>(0x10);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct breakpoint : Any {
        byte code = static_cast<byte>(0xca);
        bool reserved = false;
        //stackpop
        //stackpush undefined
    };

    struct caload : Any {
        byte code = static_cast<byte>(0x34);
        bool reserved = false;
        //stackpop arrayref, index
        //stackpush  value
    };

    struct castore : Any {
        byte code = static_cast<byte>(0x55);
        bool reserved = false;
        //stackpop arrayref, index, value
        //stackpush
    };

    struct checkcast : Any {
        byte code = static_cast<byte>(0xc0);
        bool reserved = false;
        //stackpop objectref
        //stackpush  objectref
    };

    struct d2f : Any {
        byte code = static_cast<byte>(0x90);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct d2i : Any {
        byte code = static_cast<byte>(0x8e);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct d2l : Any {
        byte code = static_cast<byte>(0x8f);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct dadd : Any {
        byte code = static_cast<byte>(0x63);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct daload : Any {
        byte code = static_cast<byte>(0x31);
        bool reserved = false;
        //stackpop arrayref, index
        //stackpush  value
    };

    struct dastore : Any {
        byte code = static_cast<byte>(0x52);
        bool reserved = false;
        //stackpop arrayref, index, value
        //stackpush
    };

    struct dcmpg : Any {
        byte code = static_cast<byte>(0x98);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct dcmpl : Any {
        byte code = static_cast<byte>(0x97);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct dconst_0 : Any {
        byte code = static_cast<byte>(0x0e);
        bool reserved = false;
        //stackpop
        //stackpush  0.0
    };

    struct dconst_1 : Any {
        byte code = static_cast<byte>(0x0f);
        bool reserved = false;
        //stackpop
        //stackpush  1.0
    };

    struct ddiv : Any {
        byte code = static_cast<byte>(0x6f);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct dload : Any {
        byte code = static_cast<byte>(0x18);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct dload_0 : Any {
        byte code = static_cast<byte>(0x26);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct dload_1 : Any {
        byte code = static_cast<byte>(0x27);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct dload_2 : Any {
        byte code = static_cast<byte>(0x28);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct dload_3 : Any {
        byte code = static_cast<byte>(0x29);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct dmul : Any {
        byte code = static_cast<byte>(0x6b);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct dneg : Any {
        byte code = static_cast<byte>(0x77);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct drem : Any {
        byte code = static_cast<byte>(0x73);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct dreturn : Any {
        byte code = static_cast<byte>(0xaf);
        bool reserved = false;
        //stackpop value
        //stackpush  [empty]
    };

    struct dstore : Any {
        byte code = static_cast<byte>(0x39);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct dstore_0 : Any {
        byte code = static_cast<byte>(0x47);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct dstore_1 : Any {
        byte code = static_cast<byte>(0x48);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct dstore_2 : Any {
        byte code = static_cast<byte>(0x49);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct dstore_3 : Any {
        byte code = static_cast<byte>(0x4a);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct dsub : Any {
        byte code = static_cast<byte>(0x67);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct dup : Any {
        byte code = static_cast<byte>(0x59);
        bool reserved = false;
        //stackpop value
        //stackpush  value, value
    };

    struct dup_x1 : Any {
        byte code = static_cast<byte>(0x5a);
        bool reserved = false;
        //stackpop value2, value1
        //stackpush  value1, value2, value1
    };

    struct dup_x2 : Any {
        byte code = static_cast<byte>(0x5b);
        bool reserved = false;
        //stackpop value3, value2, value1
        //stackpush  value1, value3, value2, value1
    };

    struct dup2 : Any {
        byte code = static_cast<byte>(0x5c);
        bool reserved = false;
        //stackpop {value2, value1}
        //stackpush  {value2, value1}, {value2, value1}
    };

    struct dup2_x1 : Any {
        byte code = static_cast<byte>(0x5d);
        bool reserved = false;
        //stackpop value3, {value2, value1}
        //stackpush  {value2, value1}, value3, {value2, value1}
    };

    struct dup2_x2 : Any {
        byte code = static_cast<byte>(0x5e);
        bool reserved = false;
        //stackpop {value4, value3}, {value2, value1}
        //stackpush  {value2, value1}, {value4, value3}, {value2, value1}
    };

    struct f2d : Any {
        byte code = static_cast<byte>(0x8d);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct f2i : Any {
        byte code = static_cast<byte>(0x8b);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct f2l : Any {
        byte code = static_cast<byte>(0x8c);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct fadd : Any {
        byte code = static_cast<byte>(0x62);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct faload : Any {
        byte code = static_cast<byte>(0x30);
        bool reserved = false;
        //stackpop arrayref, index
        //stackpush  value
    };

    struct fastore : Any {
        byte code = static_cast<byte>(0x51);
        bool reserved = false;
        //stackpop arrayref, index, value
        //stackpush
    };

    struct fcmpg : Any {
        byte code = static_cast<byte>(0x96);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct fcmpl : Any {
        byte code = static_cast<byte>(0x95);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct fconst_0 : Any {
        byte code = static_cast<byte>(0x0b);
        bool reserved = false;
        //stackpop
        //stackpush  0.0f
    };

    struct fconst_1 : Any {
        byte code = static_cast<byte>(0x0c);
        bool reserved = false;
        //stackpop
        //stackpush  1.0f
    };

    struct fconst_2 : Any {
        byte code = static_cast<byte>(0x0d);
        bool reserved = false;
        //stackpop
        //stackpush  2.0f
    };

    struct fdiv : Any {
        byte code = static_cast<byte>(0x6e);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct fload : Any {
        byte code = static_cast<byte>(0x17);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct fload_0 : Any {
        byte code = static_cast<byte>(0x22);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct fload_1 : Any {
        byte code = static_cast<byte>(0x23);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct fload_2 : Any {
        byte code = static_cast<byte>(0x24);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct fload_3 : Any {
        byte code = static_cast<byte>(0x25);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct fmul : Any {
        byte code = static_cast<byte>(0x6a);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct fneg : Any {
        byte code = static_cast<byte>(0x76);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct frem : Any {
        byte code = static_cast<byte>(0x72);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct freturn : Any {
        byte code = static_cast<byte>(0xae);
        bool reserved = false;
        //stackpop value
        //stackpush  [empty]
    };

    struct fstore : Any {
        byte code = static_cast<byte>(0x38);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct fstore_0 : Any {
        byte code = static_cast<byte>(0x43);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct fstore_1 : Any {
        byte code = static_cast<byte>(0x44);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct fstore_2 : Any {
        byte code = static_cast<byte>(0x45);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct fstore_3 : Any {
        byte code = static_cast<byte>(0x46);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct fsub : Any {
        byte code = static_cast<byte>(0x66);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct getfield : Any {
        byte code = static_cast<byte>(0xb4);
        bool reserved = false;
        //stackpop objectref
        //stackpush  value
    };

    struct getstatic : Any {
        byte code = static_cast<byte>(0xb2);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct _goto : Any {
        byte code = static_cast<byte>(0xa7);
        bool reserved = false;
    };

    struct goto_w : Any {
        byte code = static_cast<byte>(0xc8);
        bool reserved = false;
    };

    struct i2b : Any {
        byte code = static_cast<byte>(0x91);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct i2c : Any {
        byte code = static_cast<byte>(0x92);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct i2d : Any {
        byte code = static_cast<byte>(0x87);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct i2f : Any {
        byte code = static_cast<byte>(0x86);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct i2l : Any {
        byte code = static_cast<byte>(0x85);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct i2s : Any {
        byte code = static_cast<byte>(0x93);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct iadd : Any {
        byte code = static_cast<byte>(0x60);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct iaload : Any {
        byte code = static_cast<byte>(0x2e);
        bool reserved = false;
        //stackpop arrayref, index
        //stackpush  value
    };

    struct iand : Any {
        byte code = static_cast<byte>(0x7e);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct iastore : Any {
        byte code = static_cast<byte>(0x4f);
        bool reserved = false;
        //stackpop arrayref, index, value
        //stackpush
    };

    struct iconst_m1 : Any {
        byte code = static_cast<byte>(0x02);
        bool reserved = false;
        //stackpop
        //stackpush  -1
    };

    struct iconst_0 : Any {
        byte code = static_cast<byte>(0x03);
        bool reserved = false;
        //stackpop
        //stackpush  0
    };

    struct iconst_1 : Any {
        byte code = static_cast<byte>(0x04);
        bool reserved = false;
        //stackpop
        //stackpush  1
    };

    struct iconst_2 : Any {
        byte code = static_cast<byte>(0x05);
        bool reserved = false;
        //stackpop
        //stackpush  2
    };

    struct iconst_3 : Any {
        byte code = static_cast<byte>(0x06);
        bool reserved = false;
        //stackpop
        //stackpush  3
    };

    struct iconst_4 : Any {
        byte code = static_cast<byte>(0x07);
        bool reserved = false;
        //stackpop
        //stackpush  4
    };

    struct iconst_5 : Any {
        byte code = static_cast<byte>(0x08);
        bool reserved = false;
        //stackpop
        //stackpush  5
    };

    struct idiv : Any {
        byte code = static_cast<byte>(0x6c);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct if_acmpeq : Any {
        byte code = static_cast<byte>(0xa5);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush
    };

    struct if_acmpne : Any {
        byte code = static_cast<byte>(0xa6);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush
    };

    struct if_icmpeq : Any {
        byte code = static_cast<byte>(0x9f);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush
    };

    struct if_icmpge : Any {
        byte code = static_cast<byte>(0xa2);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush
    };

    struct if_icmpgt : Any {
        byte code = static_cast<byte>(0xa3);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush
    };

    struct if_icmple : Any {
        byte code = static_cast<byte>(0xa4);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush
    };

    struct if_icmplt : Any {
        byte code = static_cast<byte>(0xa1);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush
    };

    struct if_icmpne : Any {
        byte code = static_cast<byte>(0xa0);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush
    };

    struct ifeq : Any {
        byte code = static_cast<byte>(0x99);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct ifge : Any {
        byte code = static_cast<byte>(0x9c);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct ifgt : Any {
        byte code = static_cast<byte>(0x9d);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct ifle : Any {
        byte code = static_cast<byte>(0x9e);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct iflt : Any {
        byte code = static_cast<byte>(0x9b);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct ifne : Any {
        byte code = static_cast<byte>(0x9a);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct ifnonnull : Any {
        byte code = static_cast<byte>(0xc7);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct ifnull : Any {
        byte code = static_cast<byte>(0xc6);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct iinc : Any {
        byte code = static_cast<byte>(0x84);
        bool reserved = false;
        //stackpop [No change]
        //stackpush undefined
    };

    struct iload : Any {
        byte code = static_cast<byte>(0x15);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct iload_0 : Any {
        byte code = static_cast<byte>(0x1a);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct iload_1 : Any {
        byte code = static_cast<byte>(0x1b);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct iload_2 : Any {
        byte code = static_cast<byte>(0x1c);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct iload_3 : Any {
        byte code = static_cast<byte>(0x1d);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct impdep1 : Any {
        byte code = static_cast<byte>(0xfe);
        bool reserved = false;
        //stackpop
        //stackpush undefined
    };

    struct impdep2 : Any {
        byte code = static_cast<byte>(0xff);
        bool reserved = false;
        //stackpop
        //stackpush undefined
    };

    struct imul : Any {
        byte code = static_cast<byte>(0x68);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct ineg : Any {
        byte code = static_cast<byte>(0x74);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct instanceof : Any {
        byte code = static_cast<byte>(0xc1);
        bool reserved = false;
        //stackpop objectref
        //stackpush  result
    };

    struct invokedynamic : Any {
        byte code = static_cast<byte>(0xba);
        bool reserved = false;
        //stackpop [arg1, arg2, ...]
        //stackpush  result
    };

    struct invokeinterface : Any {
        byte code = static_cast<byte>(0xb9);
        bool reserved = false;
        //stackpop objectref, [arg1, arg2, ...]
        //stackpush  result
    };

    struct invokespecial : Any {
        byte code = static_cast<byte>(0xb7);
        bool reserved = false;
        //stackpop objectref, [arg1, arg2, ...]
        //stackpush  result
    };

    struct invokestatic : Any {
        byte code = static_cast<byte>(0xb8);
        bool reserved = false;
        //stackpop [arg1, arg2, ...]
        //stackpush  result
    };

    struct invokevirtual : Any {
        byte code = static_cast<byte>(0xb6);
        bool reserved = false;
        //stackpop objectref, [arg1, arg2, ...]
        //stackpush  result
    };

    struct ior : Any {
        byte code = static_cast<byte>(0x80);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct irem : Any {
        byte code = static_cast<byte>(0x70);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct ireturn : Any {
        byte code = static_cast<byte>(0xac);
        bool reserved = false;
        //stackpop value
        //stackpush  [empty]
    };

    struct ishl : Any {
        byte code = static_cast<byte>(0x78);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct ishr : Any {
        byte code = static_cast<byte>(0x7a);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct istore : Any {
        byte code = static_cast<byte>(0x36);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct istore_0 : Any {
        byte code = static_cast<byte>(0x3b);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct istore_1 : Any {
        byte code = static_cast<byte>(0x3c);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct istore_2 : Any {
        byte code = static_cast<byte>(0x3d);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct istore_3 : Any {
        byte code = static_cast<byte>(0x3e);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct isub : Any {
        byte code = static_cast<byte>(0x64);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct iushr : Any {
        byte code = static_cast<byte>(0x7c);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct ixor : Any {
        byte code = static_cast<byte>(0x82);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct jsr : Any {
        byte code = static_cast<byte>(0xa8);
        bool reserved = false;
        //stackpop
        //stackpush  address
    };

    struct jsr_w : Any {
        byte code = static_cast<byte>(0xc9);
        bool reserved = false;
        //stackpop
        //stackpush  address
    };

    struct l2d : Any {
        byte code = static_cast<byte>(0x8a);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct l2f : Any {
        byte code = static_cast<byte>(0x89);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct l2i : Any {
        byte code = static_cast<byte>(0x88);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct ladd : Any {
        byte code = static_cast<byte>(0x61);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct laload : Any {
        byte code = static_cast<byte>(0x2f);
        bool reserved = false;
        //stackpop arrayref, index
        //stackpush  value
    };

    struct land : Any {
        byte code = static_cast<byte>(0x7f);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct lastore : Any {
        byte code = static_cast<byte>(0x50);
        bool reserved = false;
        //stackpop arrayref, index, value
        //stackpush
    };

    struct lcmp : Any {
        byte code = static_cast<byte>(0x94);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct lconst_0 : Any {
        byte code = static_cast<byte>(0x09);
        bool reserved = false;
        //stackpop
        //stackpush  0L
    };

    struct lconst_1 : Any {
        byte code = static_cast<byte>(0x0a);
        bool reserved = false;
        //stackpop
        //stackpush  1L
    };

    struct ldc : Any {
        byte code = static_cast<byte>(0x12);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct ldc_w : Any {
        byte code = static_cast<byte>(0x13);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct ldc2_w : Any {
        byte code = static_cast<byte>(0x14);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct ldiv : Any {
        byte code = static_cast<byte>(0x6d);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct lload : Any {
        byte code = static_cast<byte>(0x16);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct lload_0 : Any {
        byte code = static_cast<byte>(0x1e);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct lload_1 : Any {
        byte code = static_cast<byte>(0x1f);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct lload_2 : Any {
        byte code = static_cast<byte>(0x20);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct lload_3 : Any {
        byte code = static_cast<byte>(0x21);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct lmul : Any {
        byte code = static_cast<byte>(0x69);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct lneg : Any {
        byte code = static_cast<byte>(0x75);
        bool reserved = false;
        //stackpop value
        //stackpush  result
    };

    struct lookupswitch : Any {
        byte code = static_cast<byte>(0xab);
        bool reserved = false;
        //stackpop key
        //stackpush
    };

    struct lor : Any {
        byte code = static_cast<byte>(0x81);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct lrem : Any {
        byte code = static_cast<byte>(0x71);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct lreturn : Any {
        byte code = static_cast<byte>(0xad);
        bool reserved = false;
        //stackpop value
        //stackpush  [empty]
    };

    struct lshl : Any {
        byte code = static_cast<byte>(0x79);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct lshr : Any {
        byte code = static_cast<byte>(0x7b);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct lstore : Any {
        byte code = static_cast<byte>(0x37);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct lstore_0 : Any {
        byte code = static_cast<byte>(0x3f);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct lstore_1 : Any {
        byte code = static_cast<byte>(0x40);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct lstore_2 : Any {
        byte code = static_cast<byte>(0x41);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct lstore_3 : Any {
        byte code = static_cast<byte>(0x42);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct lsub : Any {
        byte code = static_cast<byte>(0x65);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct lushr : Any {
        byte code = static_cast<byte>(0x7d);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct lxor : Any {
        byte code = static_cast<byte>(0x83);
        bool reserved = false;
        //stackpop value1, value2
        //stackpush  result
    };

    struct monitorenter : Any {
        byte code = static_cast<byte>(0xc2);
        bool reserved = false;
        //stackpop objectref
        //stackpush
    };

    struct monitorexit : Any {
        byte code = static_cast<byte>(0xc3);
        bool reserved = false;
        //stackpop objectref
        //stackpush
    };

    struct multianewarray : Any {
        byte code = static_cast<byte>(0xc5);
        bool reserved = false;
        //stackpop count1, [count2,...]
        //stackpush  arrayref
    };

    struct _new : Any {
        byte code = static_cast<byte>(0xbb);
        bool reserved = false;
        //stackpop
        //stackpush  objectref
    };

    struct newarray : Any {
        byte code = static_cast<byte>(0xbc);
        bool reserved = false;
        //stackpop count
        //stackpush  arrayref
    };

    struct nop : Any {
        byte code = static_cast<byte>(0x00);
        bool reserved = false;
        //stackpop [No change]
        //stackpush undefined
    };

    struct pop : Any {
        byte code = static_cast<byte>(0x57);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct pop2 : Any {
        byte code = static_cast<byte>(0x58);
        bool reserved = false;
        //stackpop {value2, value1}
        //stackpush
    };

    struct putfield : Any {
        byte code = static_cast<byte>(0xb5);
        bool reserved = false;
        //stackpop objectref, value
        //stackpush
    };

    struct putstatic : Any {
        byte code = static_cast<byte>(0xb3);
        bool reserved = false;
        //stackpop value
        //stackpush
    };

    struct ret : Any {
        byte code = static_cast<byte>(0xa9);
        bool reserved = false;
        //stackpop [No change]
        //stackpush undefined
    };

    struct _return : Any {
        byte code = static_cast<byte>(0xb1);
        bool reserved = false;
        //stackpop
        //stackpush  [empty]
    };

    struct saload : Any {
        byte code = static_cast<byte>(0x35);
        bool reserved = false;
        //stackpop arrayref, index
        //stackpush  value
    };

    struct sastore : Any {
        byte code = static_cast<byte>(0x56);
        bool reserved = false;
        //stackpop arrayref, index, value
        //stackpush
    };

    struct sipush : Any {
        byte code = static_cast<byte>(0x11);
        bool reserved = false;
        //stackpop
        //stackpush  value
    };

    struct swap : Any {
        byte code = static_cast<byte>(0x5f);
        bool reserved = false;
        //stackpop value2, value1
        //stackpush  value1, value2
    };

    struct tableswitch : Any {
        byte code = static_cast<byte>(0xaa);
        bool reserved = false;
        //stackpop index
        //stackpush
    };

    struct wide : Any {
        byte code = static_cast<byte>(0xc4);
        bool reserved = false;
        //stackpop [same as for corresponding instructions]
        //stackpush undefined
    };
} instruction;
