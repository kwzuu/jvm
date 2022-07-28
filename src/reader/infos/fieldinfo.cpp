#include "../Reader.h"
#include "../../lib/lib.h"
#include <vector>

FieldInfo ClassReader::read_fieldinfo() {
    
    u2 access_flags     = read_u2();
    u2 name_index       = read_u2();
    u2 descriptor_index = read_u2();
    u2 attributes_count = read_u2();

    std::vector<AttributeInfo> attributes(attributes_count);
    for (int i = 0; i < attributes_count; i++) {
        attributes[i] = read_attributeinfo();
    }
    return FieldInfo (
        access_flags,
        name_index,
        descriptor_index,
        attributes_count,
        attributes
    );
    

}