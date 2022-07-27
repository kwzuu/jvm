//
// Created by lexi on 2022-07-27.
//

#include "Reader.h"
#include "../lib/lib.h"

ClassReader::ClassReader(char *path) {
    file = fopen(path, "r");
    if (!file) {
        halt_and_catch_fire("class does not exist", 1);
    }
}


long ClassReader::tell() {
    return ftell(this->file);
}

template<class T>
T ClassReader::read() {
    char buf[sizeof(T)];
    fread(buf, sizeof(T), 1, file);
    return *reinterpret_cast<T*>(buf); // hot girl (lexi) shit right here
}

template<class T>
T ClassReader::read_inplace() {
    long pos = tell();
    auto x = read<T>();
    seek(pos, SEEK_SET);
    return x;
}

std::string ClassReader::read_n(long n) {
    char *s = static_cast<char *>(calloc(sizeof(char), n));
    fread(s, n, 1, file);
    return s;
}

void ClassReader::seek(long offset, int whence) {
    fseek(file, offset, whence);
}


CpInfo ClassReader::read_cpinfo() {
    CpInfo result;
    u1 tag = this->read_inplace<u1>();
    switch (tag) {
        case 0:
            break;
        default:
            halt_and_catch_fire("invalid constant pool info tag\n", 1);
    }
    return result;
}
