#include "./vm.h"
#include <vector>
#include "../lib/lib.h"
#include <string.h>
#include <cstring>
#include <iostream>
#include "../flags.h"
#include "../fmt.h"
using std::vector;


MethodInfo VM::getMethod(char *classpath, char *methodname)
{
    Class clazz = getClass(classpath);
    for (auto m : clazz.methods) {
        auto method_name = clazz.method_name(&m);

        fprintf(stderr, "Method %s.%s\n", classpath, method_name);


        if (strcmp(method_name, methodname) == 0) {
            return m;
        }
    }
    fprintf(stderr, "Method %s not found in Class %s\n", methodname, classpath);
    exit(1);
}

void VM::