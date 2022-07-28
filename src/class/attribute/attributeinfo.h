#pragma once

#include <vector>
#include "../../types.h"
struct AttributeInfo {
    u2 attribute_name_index;
    u4 attribute_length;
    std::vector<u1> info;
};