#include "fmt.h"
#include "lib/lib.h"
#include <cstring>
#include <memory>
#include <string>
#include <stdexcept>

using std::string;

template<typename ... Args>
string format( const std::string& format, Args ... args ) {
    int size_s = std::snprintf( nullptr, 0, format.c_str(), args ... ) + 1; // Extra space for '\0'
    if( size_s <= 0 ){ throw std::runtime_error( "Error during formatting." ); }
    auto size = static_cast<size_t>( size_s );
    std::unique_ptr<char[]> buf( new char[ size ] );
    std::snprintf( buf.get(), size, format.c_str(), args ... );
    return std::string( buf.get(), buf.get() + size - 1 ); // We don't want the '\0' inside
}

string add_null_term(size_t len, u1 *s) {
    auto ret = new char[len + 1];
    ret[len] = '\0';
    memcpy(ret, s, len);
    return ret;
}



string fmt(JClass c) {
    return format("Class { name: #%d }", c.name_index);
}

string fmt(JFieldref fr) {
    return format("Fieldref { class: #%d, nt: #%d }",
                  fr.class_index, fr.name_and_type_index);
}

string fmt(JMethodref mr) {
    return format("Methodref { class: #%d, nt: #%d }",
                  mr.class_index, mr.name_and_type_index);
}

string fmt(JInterfaceMethodref mr) {
    return format("InterfaceMethodref { class: #%d, nt: #%d }",
                  mr.class_index, mr.name_and_type_index);
}

string fmt(JString s) {
    return format("String { string: #%d }",
                  s.string_index);
}

string fmt(JInteger s) {
    return format("Integer { bytes: %08x (%d) }",
                  s.bytes, s.bytes);
}

string fmt(JFloat s) {
    return format("Float { bytes: %08x (%f) }",
                  s.bytes, s.bytes);
}

string fmt(JLong _l) {
    long l = (long) _l.upper << 32 | _l.lower;
    return format("Long { bytes: %016x (%l) }",
                  l, l);
}

string fmt(JDouble d) {
    union { double d; uint64_t l; } u;
    u.l = (uint64_t) d.upper << 32 | d.lower;
    return format("Long { bytes: %016x (%lf) }",
                  u.d, u.d);
}

string fmt(JNameAndType nt) {
    return format("NameAndType { name: #%d, type: #%d }",
                  nt.name_index, nt.type_index);
}

string fmt(JUtf8 s) {
    return format("Utf8", add_null_term(s.length, s.data));
}

string fmt(JMethodHandle mh) {
    return format("MethodHandle { reference: #%d, kind: %02x }",
                  mh.reference_index, mh.reference_kind);
}

string fmt(JMethodType mt) {
    return format("MethodType { descriptor: #%d }",
                  mt.descriptor_index);
}

string fmt(JInvokeDynamic id) {
    return format("InvokeDynamic { name_and_type: #%d, bootstrap_method_attr: #%d }",
        id.name_and_type_index, id.bootstrap_method_attr_index);
}

string fmt(CpInfo cpi) {
    switch (cpi.any.tag) {
        case 7:
            return fmt(cpi.j_class);
        case 9:
            return fmt(cpi.j_fieldref);
        case 10:
            return fmt(cpi.j_methodref);
        case 11:
            return fmt(cpi.j_interfacemethodref);
        case 8:
            return fmt(cpi.j_string);
        case 3:
            return fmt(cpi.j_integer);
        case 4:
            return fmt(cpi.j_float);
        case 5:
            return fmt(cpi.j_long);
        case 6:
            return fmt(cpi.j_double);
        case 12:
            return fmt(cpi.j_nameandtype);
        case 1:
            return fmt(cpi.j_utf8);
        case 15:
            return fmt(cpi.j_methodhandle);
        case 16:
            return fmt(cpi.j_methodtype);
        case 18:
            return fmt(cpi.j_invokedynamic);
        default:
            halt_and_catch_fire(1, "invaid cpinfo format tag: %d\n", cpi.any.tag)
    }
}