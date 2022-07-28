#include "../Reader.h"
#include "../../lib/lib.h"
#include "../../class/constant_pool/cpinfo.h"

CpInfo ClassReader::read_cpinfo() {
    CpInfo result;
    u1 tag = read_u1();
    result.any.tag = tag;
    u2 size;
    switch (tag) {
        //! text
        case 1:
            size = read_u2(); 
            result.j_utf8 = JUtf8 {
                .length = size,
                .data = read_n(size), 
            };
            break;

        //! primitives
        case 3:
            result.j_integer = JInteger {
                .bytes = read_u4(),
            };
            break;
        case 4:
            result.j_float = JFloat {
                .bytes = read_u4(),
            };
            break;
        case 5:
            result.j_long = JLong {
                .upper = read_u4(),
                .lower = read_u4(),
            };
            break;
        case 6:
            result.j_double = JDouble {
                .upper = read_u4(),
                .lower = read_u4(),
            };
            break;

        //! class
        case 7:
            result.j_class = JClass {
                .name_index = read_u2(),
            };
            break;

        //! string
        case 8:
            result.j_string = JString {
                .string_index = read_u2(),
            };
            break;

        //! references
        case 9:
            result.j_fieldref = JFieldref {
                .class_index = read_u2(),
                .name_and_type_index = read_u2(),
            };
            break;
        case 10:
            result.j_methodref = JMethodref {
                .class_index = read_u2(),
                .name_and_type_index = read_u2(),
            };
            break;
        case 11:
            result.j_interfacemethodref = JInterfaceMethodref {
                .class_index = read_u2(),
                .name_and_type_index = read_u2(),
            };
            break;
        case 12:
            result.j_nameandtype = JNameAndType {
                .name_index = read_u2(),
                .type_index = read_u2(),
            };
            break;

        //! handle
        case 15:
            result.j_methodhandle = JMethodHandle {
                .reference_kind = read_u1(),
                .reference_index = read_u2(),
            };
            break;

        //! thingy
        case 16:
            result.j_methodtype = JMethodType {
                .descriptor_index = read_u2(),
            };
            break;

        //! doohickey
        case 18:
            result.j_invokedynamic = JInvokeDynamic {
                .bootstrap_method_attr_index = read_u2(),
                .name_and_type_index = read_u2(),
            };
            break;

        default:
            halt_and_catch_fire(1, "invalid constant pool info tag 0x%02x\n", tag);
    }
    return result;
}