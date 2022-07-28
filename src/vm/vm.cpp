#include "./vm.h"
#include <vector>
#include "../lib/lib.h"
#include <string.h>
#include <cstring>
#include <iostream>
#include "../flags.h"
#include "../fmt.h"
using std::vector;



void VM::displayAllCpInfo(char *classpath) {
    Class clazz = getClass(classpath);
    auto cp_len = clazz.constant_pool.size();
    for (unsigned long i = 0; i < cp_len; i++) {
        auto cp = clazz.constant_pool[i];
        printf("%d: %s\n", static_cast<int>(i), fmt(cp).c_str());
    }
}

VM::VM(int argc. char **argv) {
    // Load classes
    for (int i = 1; i < argc; i++) {
        loadClass(getClass(argv[i]));
    }
}

VM::~VM() {

}

bool VM::verifyValidBytecodeVersion(uint32_t version) {
    u2 major = (version >> 16) & 0xFFFF;
    u2 minor = (version >> 8) & 0xFF;
    if (!major <= 55) {
        fprintf(stderr, "Bytecode version %d.%d is not supported\n", major, minor);
        exit(1);
    }

}