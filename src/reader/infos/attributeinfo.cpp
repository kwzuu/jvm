#include "../Reader.h"
#include "../../lib/lib.h"
#include  <vector>
AttributeInfo ClassReader::read_attributeinfo() {
    u2 attribute_name_index = read_u2();
    u4 attribute_length = read_u4();
    std::vector<u1> info(attribute_length);
    for (u4 i = 0; i < attribute_length; i++) {
        info[i] = read_u1();
    }
    return AttributeInfo {
        attribute_name_index,
        attribute_length,
        info
    };
}

