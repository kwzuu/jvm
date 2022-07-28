//
// Created by aenri on 7/28/22.
//
#include "./vm.h"
#include <vector>
#include "../lib/lib.h"
#include <string.h>
#include <iostream>
#include "../reader/Reader.h"
using std::vector;

void VM::loadClass(char* classFile)
{
    ClassReader reader(classFile);
    Class clazz = reader.readClass();
}
Class VM::getClass(char *classpath)
{
    if (classmap.find(classpath) == classmap.end()) {
        fprintf(stderr, "Class %s not found\n", classpath);
        exit(1);
    }
    return classmap[classpath];
}