
#include "./lib.h"
#include "../class/Class.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

char* parse_jutf8(JUtf8 jutf) {
    char* str = (char*)malloc(jutf.length + 1);
    memcpy(str, jutf.data, jutf.length);
    str[jutf.length] = '\0';
    return str;
}