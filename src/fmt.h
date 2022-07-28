#pragma once
#include "class/constant_pool/cpinfo.h"
#include "class/Class.h"
#include <string>

std::string add_null_term(size_t len, u1 *s);

std::string fmt(CpInfo cpi);

std::string fmt(JUtf8 s);
std::string fmt(JClass c);
std::string fmt(JFieldref fr);
std::string fmt(JMethodref mr);
std::string fmt(JInterfaceMethodref mr);
std::string fmt(JString s);
std::string fmt(AttributeInfo nfo);
