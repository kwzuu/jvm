#include <vector>

#include "constant_pool/cpinfo.h"
#include "field/fieldinfo.h"
#include "method/methodinfo.h"
#include "attribute/attributeinfo.h"
#include "access_flags.h"

using std::vector;

struct Class {
    u4 magic;
    u2 minor;
    u2 major;
    u2 constant_pool_count;
    vector<CpInfo> constant_pool;
    u2 access_flags;
    u2 this_class;
    u2 super_class;
    u2 interfaces_count;
    vector<u2> interfaces;
    u2 fields_count;
    vector<FieldInfo> fields;
    u2 methods_count;
    vector<MethodInfo> methods;
    u2 attributes_count;
    vector<AttributeInfo> attributes;

    bool shallow_verify();
    int version_compare(Class *that);
};