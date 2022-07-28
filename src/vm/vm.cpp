#include "./vm.h"
#include <vector>
#include "../lib/lib.h"
#include <string.h>
#include <cstring>
#include <iostream>
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
        if (strcmp(clazz.method_name(m), methodname) == 0) {
            return m;
        }
    }
    fprintf(stderr, "Method %s not found in Class %s\n", methodname, classpath);
    exit(1);
}

VM::VM() {

}

VM::~VM() {

}