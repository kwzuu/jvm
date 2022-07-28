#include "./Class.h"
// #include "../fmt.h"
#include "../lib/lib.h"
#include <cstdio>
#include <string.h>
#include <cstring>
bool Class::shallow_verify() {
    return magic == JAVA_MAGIC_NUMBER;
}

int Class::version_compare(Class *that) {
    int ver1 =       major << 16 |       minor; 
    int ver2 = that->major << 16 | that->minor;
    return (ver1 < ver2) - (ver1 > ver2);
}

char* Class::name() {
    // get this_class, then parse the J_utf8 it links to
    auto utf8_ptr = constant_pool[
        constant_pool[
            this_class - 1
            ].j_class.name_index - 1
        ].j_utf8;
    return parse_jutf8(utf8_ptr);
}
char* Class::method_name(MethodInfo *nfo) {
    auto utf8_ptr = constant_pool [
        nfo->name_index -1
    ].j_utf8;
    return parse_jutf8(utf8_ptr);
}
