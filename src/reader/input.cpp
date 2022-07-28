#include "Reader.h"

long ClassReader::tell() { return ftell(file); }

template<class T>
T ClassReader::read() {
    char buf[sizeof(T)];
    fread(buf, sizeof(T), 1, file);
    return *reinterpret_cast<T *>(buf); // hot girl (lexi) shit right here
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
