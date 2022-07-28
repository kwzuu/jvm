#include <iostream>
#include "reader/Reader.h"

#ifdef TEST
int main() {

}
#else
int main(int argc, char **argv) {
    if (argc < 1) {
        fprintf(stderr, "specify main class");
        return 1;
    }
    ClassReader main_class(argv[1]);
    main_class.load();
}
#endif