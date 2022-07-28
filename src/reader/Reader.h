#pragma once
//
// Created by lexi on 2022-07-27.
//

#include <cstdint>
#include <cstdio>
#include <string>
#include "../class/Class.h"
#include "../class/constant_pool/cpinfo.h"
#include "../class/method/methodinfo.h"

class ClassReader {
public:
    explicit ClassReader(char *path);

    long tell();
    void seek(long offset, int whence);

    u1 read_u1();
    u2 read_u2();
    u4 read_u4();
    
    u1 *read_n(long n);
    char* read_utf8(u2 length);

    CpInfo read_cpinfo();
    FieldInfo read_fieldinfo();
    AttributeInfo read_attributeinfo();
    MethodInfo read_methodinfo();

    Class load();

private:
    FILE *file;
};
// typedef void* MethodInfo; // dont worry this is just a placeholder
