
#include "./Class.h"
#include "../constants.h"
bool Class::shallow_verify() {
    return magic == JAVA_MAGIC_NUMBER;
}
int Class::version_compare(Class *that) {
    int ver1 =       major << 16 |       minor; 
    int ver2 = that->major << 16 | that->minor;
    return (ver1 < ver2) - (ver1 > ver2);
}
