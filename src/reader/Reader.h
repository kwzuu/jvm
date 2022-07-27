//
// Created by lexi on 2022-07-27.
//

#ifndef JVM_READER_H
#define JVM_READER_H


#include <cstdint>
#include <cstdio>
#include <string>
#include "../constant_pool/cpinfo.h"

class ClassReader {
public:
    explicit ClassReader(char *path);

    long tell();
    void seek(long offset, int whence);

    template<class T>
    T read();
    std::string read_n(long n);
    CpInfo read_cpinfo();

    template<class T>
    T read_inplace();

    Class load();
private:
    FILE *file;
};


#endif //JVM_READER_H
