#define halt_and_catch_fire(err, code) {\
    fprintf(stderr, "%s\n", err);\
    exit(code);\
}

int compareVersions(Class clazz1, Class clazz2);