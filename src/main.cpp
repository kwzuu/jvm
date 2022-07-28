#include <iostream>
#include "reader/Reader.h"
#include <cstdlib>
#include <cstring>

//#define TEST

char *add_null_term(size_t len, u1 *s) {
    auto ret = new char[len + 1];
    ret[len] = '\0';
    memcpy(ret, s, len);
    return ret;
}

char *fmt(JUtf8 s) {
    return add_null_term(s.length, s.data);
}

#ifdef TEST
int main(int argc, char **argv) {
    if (argc < 1) {
        fprintf(stderr, "specify main class");
        return 1;
    }
    ClassReader main_class(argv[1]);
    printf("read_u4: 0x%08x\n", main_class.read_u4());
    main_class.seek(0, SEEK_SET);
    printf("read_u2: 0x%04x\n", main_class.read_u2());
    main_class.seek(0, SEEK_SET);
    printf("read_u1: 0x%02x\n", main_class.read_u1());
    main_class.seek(0, SEEK_SET);
}
#else
int main(int argc, char **argv) {
    if (argc < 1) {
        fprintf(stderr, "specify main class");
        return 1;
    }
    ClassReader main_class(argv[1]);
    auto cls = main_class.load();
    
    auto this_class = cls.constant_pool[cls.this_class - 1];
    auto this_name = cls.constant_pool[this_class.j_class.name_index - 1].j_utf8;

    auto super_class = cls.constant_pool[cls.super_class - 1];
    auto super_name = cls.constant_pool[super_class.j_class.name_index - 1].j_utf8;

    printf("magic: %08x\n", cls.magic);
    printf("minor: %04x\n", cls.minor);
    printf("major: %04x\n", cls.major);
    printf("this_class: #%d (%s)\n", cls.this_class, fmt(this_name));
    printf("super_class: #%d (%s)\n", cls.super_class, fmt(super_name));
}
#endif