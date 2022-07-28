
#include "./lib.h"
#include "../class/Class.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

char* reinterpret_utf8p(JUtf8* ptr) {
    // reconstruct utf8 string from JUtf8
    char* str = (char*)malloc(ptr->length + 1);
    memcpy(str, ptr->data, ptr->length);
    str[ptr->length] = '\0';
    return str;
}