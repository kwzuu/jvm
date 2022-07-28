
#include "../Reader.h"
#include "../../lib/lib.h"

CpInfo ClassReader::read_cpinfo() {
    CpInfo result;
    u1 tag = this->read_inplace<u1>();
    switch (tag) {
        case 0:
            break;
        default:
            halt_and_catch_fire("invalid constant pool info tag\n", 1);
    }
    return result;
}