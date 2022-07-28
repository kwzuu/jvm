#include "./vm.h"
#include <vector>
#include "../lib/lib.h"
#include <string.h>
#include <cstring>
#include <iostream>
#include "../flags.h"
#include "../fmt.h"
using std::vector;

void VM::loadClass(Class clazz)
{
    classes.push_back(clazz);
}
Class VM::getClass(char *classpath)
{
    for (long unsigned int i = 0; i < classes.size(); i++)
    {
        if (strcmp(classes[i].name(), classpath) == 0)
        {
            return classes[i];
        }
    }
    fprintf(stderr, "Class %s not found\n", classpath);
    exit(1);
}
MethodInfo VM::getMethod(char *classpath, char *methodname)
{
    Class clazz = getClass(classpath);
    for (auto m : clazz.methods) {
        auto method_name = clazz.method_name(&m);

        printf("Method name found as %s\n", method_name);


        if (strcmp(method_name, methodname) == 0) {
            return m;
        }
    }
    fprintf(stderr, "Method %s not found in Class %s\n", methodname, classpath);
    exit(1);
}

void VM::displayAllCpInfo(char *classpath) {
    Class clazz = getClass(classpath);
    auto cp_len = clazz.constant_pool.size();
    for (unsigned long i = 0; i < cp_len; i++) {
        auto cp = clazz.constant_pool[i];
        printf("%d: %s\n", static_cast<int>(i), fmt(cp).c_str());
    }
}

VM::VM() {

}

VM::~VM() {

}