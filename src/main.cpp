#include <iostream>
#include "reader/Reader.h"
#include <cstdlib>
#include <cstring>
#include "./class/method/instr/instr.h"
#include "fmt.h"
#include "vm/vm.h"

void vm_open(ClassReader main_class); 

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
using std::cout;

int main(int argc, char **argv) {
    if (argc < 1) {
        fprintf(stderr, "specify main class");
        return 1;
    }
    ClassReader main_class(argv[1]);

//    cout << fmt(main_class) << std::endl;
    vm_open(main_class);
}
#endif

// void cpinfo_parse_test(ClassReader main_class) {
//     auto cls = main_class.load();
    
//     auto this_class = cls.constant_pool[cls.this_class - 1];
//     auto this_name = cls.constant_pool[this_class.j_class.name_index - 1];

//     auto super_class = cls.constant_pool[cls.super_class - 1];
//     auto super_name = cls.constant_pool[super_class.j_class.name_index - 1];

//     printf("magic: 0x%08x\n", cls.magic);
//     printf("minor: 0x%04x\n", cls.minor);
//     printf("major: 0x%04x\n", cls.major);
//     printf("constant pool {\n");
    
//     int i = 0;
//     for (CpInfo c : cls.constant_pool) {
//         i++;
//         cout << fmt(c) << '\n';
//     }

//     printf("}\n");
//     printf("this_class: #%d (%s)\n",
//            cls.this_class, &fmt(this_name)[0]);
//     printf("super_class: #%d (%s)\n",
//            cls.super_class, &fmt(super_name)[0]);
// }

void vm_open(ClassReader main_class) {
    auto vm = VM();
    auto cls = main_class.load();
    vm.loadClass(cls);
    auto classpath = const_cast<char *>("Main");
//    auto method = const_cast<char *>("main");
    vm.displayAllCpInfo(classpath);

}