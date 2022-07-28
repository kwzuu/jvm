#include "Reader.h"

long ClassReader::tell() { return ftell(file); }

u1 ClassReader::read_u1() {
    char buf[1];
    fread(buf, sizeof(u1), 1, file);
    return *reinterpret_cast<u1 *>(buf); // hot girl (lexi) shit right here
}

u2 ClassReader::read_u2() {
    return read_u1() << 8 | read_u1();
}

u4 ClassReader::read_u4() {
    return read_u2() << 16 | read_u2();
}

u1 *ClassReader::read_n(long n) {
    char *s = static_cast<char *>(calloc(sizeof(char), n));
    fread(s, n, 1, file);
    return reinterpret_cast<u1 *>(s);
}

void ClassReader::seek(long offset, int whence) {
    fseek(file, offset, whence);
}
