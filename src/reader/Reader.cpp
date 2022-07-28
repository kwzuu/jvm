//
// Created by lexi on 2022-07-27.
//

#include "Reader.h"
#include "../lib/lib.h"
#include "../class/Class.h"
ClassReader::ClassReader(char *path) {
    file = fopen(path, "r");
    if (!file) {
        halt_and_catch_fire("class does not exist", 1);
    }
}




Class ClassReader::load() {
    nimpl();

    //! beginning
    u4 magic = read<u4>();
    u2 major_ver = read<u2>();
    u2 minor_ver = read<u2>();

    //! constant pool
    u2 cpinfo_count = read<u2>();
    std::vector<CpInfo> constant_pool(cpinfo_count - 1);
    for(int i = 0; i < (cpinfo_count - 1); i++) {
        constant_pool[i] = read_cpinfo();
    }

    //! misc data (not important)
    u2 access_flags = read<u2>();
    u2 this_class = read<u2>();
    u2 super_class = read<u2>();
    
    //! interfaces
    u2 interfaces_count = read<u2>();
    vector<u2> interfaces(interfaces_count); // FIXMEEEE: what
    
    
    //! fields
    u2 fields_count = read<u2>();
    std::vector<FieldInfo> fields;
    fields.reserve(fields_count);
    for(int i = 0; i < fields_count; i++) {
        fields[i] = read_fieldinfo();
    }
        
    
    //! methods
    u2 methods_count = read<u2>();
    std::vector<MethodInfo> method_infos;
    method_infos.reserve(methods_count);
    for (int i = 0; i < methods_count; i++) {
        method_infos[i] = read_methodinfo();
    }

    //! attributes
    u2 attributes_count = read<u2>();
    std::vector<AttributeInfo> attribute_infos;
    attribute_infos.reserve(attributes_count);
    for (int i = 0; i < attributes_count; i++) {
        attribute_infos[i] = read_attributeinfo();
    }
    
    return Class {
        .magic = magic,
        .minor = minor_ver,
        .major = major_ver,
        .constant_pool_count = cpinfo_count,
        .constant_pool = constant_pool,
        .access_flags = access_flags,
        .this_class = this_class,
        .super_class = super_class,
        .interfaces_count = interfaces_count,
        .interfaces = interfaces,
        .fields_count = fields_count,
        .fields = fields,
        .methods_count = methods_count,
        .methods = method_infos,
        .attributes_count = attributes_count,
        .attributes = attribute_infos,
    };
}