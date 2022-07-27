//
// Created by lexi on 2022-07-27.
//

#ifndef JVM_CPINFO_H
#define JVM_CPINFO_H

#include <cstdint>

#define u1 uint8_t
#define u2 uint16_t
#define u4 uint32_t

struct Any {
    u1 tag;
};

struct JClass {
    u1 tag = 7;
    u2 name_index;
};

struct JFieldref {
    u1 tag = 9;
    u2 class_index;
    u2 name_and_type_index;
};

struct JMethodref {
    u1 tag = 10;
    u2 class_index;
    u2 name_and_type_index;
};

struct JInterfaceMethodref {
    u1 tag = 11;
    u2 class_index;
    u2 name_and_type_index;
};

struct JString {
    u1 tag = 8;
    u2 string_index;
};

struct JInteger {
    u1 tag = 3;
    u4 bytes;
};

struct JFloat {
    u1 tag = 4;
    u4 bytes;
};

struct JLong {
    u1 tag = 5;
    u4 upper;
    u4 lower;
};

struct JDouble {
    u1 tag = 6;
    u4 upper;
    u4 lower;
};

struct JNameAndType {
    u1 tag = 12;
    u2 name_index;
    u2 type_index;
};

struct JUtf8 {
    u1 tag = 1;
    u2 length;
    u1 *data;
};

struct JMethodHandle {
    u1 tag = 15;
    u1 reference_kind;
    u2 reference_index;
};

struct JMethodType {
    u1 tag = 16;
    u2 descriptor_index;
};

struct JInvokeDynamic {
    u1 tag = 18;
    u2 bootstrap_method_attr_index;
    u2 name_and_type_index;
};


union CpInfo {
    Any any{};
    JClass j_class;
    JFieldref j_fieldref;
    JMethodref j_methodref;
    JInterfaceMethodref j_interfacemethodref;
    JString j_string;
    JInteger j_integer;
    JFloat j_float;
    JLong j_long;
    JDouble j_double;
    JNameAndType j_nameandtype;
    JUtf8 j_utf8;
    JMethodHandle j_methodhandle;
    JMethodType j_methodtype;
    JInvokeDynamic j_invokedynamic;

    CpInfo();
};

#endif //JVM_CPINFO_H
