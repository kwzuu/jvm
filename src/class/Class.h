#include "../constant_pool/cpinfo.h"
#include "../field/fieldinfo.h"
#include "../attribute/attributeinfo.h"
#include <vector>
struct Class {
    u4 magic;
    u2 minor;
    u2 major;
    u2 constant_pool_count;
    std::vector<CpInfo> constant_pool;
    u2 access_flags;
    u2 this_class;
    u2 super_class;
    u2 interfaces_count;
    std::vector<u2> interfaces;
    u2 fields_count;
    std::vector<FieldInfo> fields;
    u2 attributes_count;
    std::vector<AttributeInfo> attributes;

    bool shallow_verify();
    int version_compare(Class *that);
};