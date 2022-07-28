//
// Created by lexi on 2022-07-27.
//

#ifndef JVM_READER_H
#define JVM_READER_H


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

    template<class T>
    T read();
    std::string read_n(long n);
    CpInfo read_cpinfo();
    FieldInfo read_fieldinfo();
    AttributeInfo read_attributeinfo();
    MethodInfo read_methodinfo();

    template<class T>
    T read_inplace();

    Class load();

private:
    FILE *file;
};
// typedef void* MethodInfo; // dont worry this is just a placeholder

#endif //JVM_READER_H
