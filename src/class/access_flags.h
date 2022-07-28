#pragma once

#include "../constants.h"
namespace access_flags {
    const u2 ACC_PUBLIC     = 0x0001;
    const u2 ACC_FINAL      = 0x0010;
    const u2 ACC_SUPER      = 0x0020;
    const u2 ACC_INTERFACE  = 0x0200;
    const u2 ACC_ABSTRACT   = 0x0400;
    const u2 ACC_SYNTHETIC  = 0x1000;
    const u2 ACC_ANNOTATION = 0x2000;
    const u2 ACC_ENUM       = 0x4000;
}