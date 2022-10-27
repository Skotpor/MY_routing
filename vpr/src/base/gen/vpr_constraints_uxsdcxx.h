#pragma once
/*
 * This file is generated by uxsdcxx 0.1.0.
 * https://github.com/duck2/uxsdcxx
 * Modify only if your build process doesn't involve regenerating this file.
 *
 * Cmdline: uxsdcxx.py vpr_constraints.xsd
 * Input file: /home/khalid88/Documents/uxsdcxx/vpr_constraints.xsd
 * md5sum of input file: 6b6011a6e6446347b234da82e517422e
 */

#include <functional>

#include <bitset>
#include <cassert>
#include <cstring>
#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <vector>

#include <stddef.h>
#include <stdint.h>
#include "pugixml.hpp"

#include "vpr_constraints_uxsdcxx_interface.h"
#include "region.h"

/* All uxsdcxx functions and structs live in this namespace. */
namespace uxsd {

/**
 * Internal function for getting line and column number from file based on
 * byte offset.
 */
inline void get_line_number(const char* filename, std::ptrdiff_t offset, int* line, int* col);

[[noreturn]] inline void noreturn_report(const std::function<void(const char*)>* report_error, const char* msg) {
    (*report_error)(msg);
    throw std::runtime_error("Unreachable!");
}

/* Declarations for internal load functions for the complex types. */
template<class T, typename Context>
inline void load_add_atom(const pugi::xml_node& root, T& out, Context& context, const std::function<void(const char*)>* report_error, ptrdiff_t* offset_debug);
template<class T, typename Context>
inline void load_add_region(const pugi::xml_node& root, T& out, Context& context, const std::function<void(const char*)>* report_error, ptrdiff_t* offset_debug);
inline void load_add_region_required_attributes(const pugi::xml_node& root, int* x_high, int* x_low, int* y_high, int* y_low, const std::function<void(const char*)>* report_error);
template<class T, typename Context>
inline void load_partition(const pugi::xml_node& root, T& out, Context& context, const std::function<void(const char*)>* report_error, ptrdiff_t* offset_debug);
template<class T, typename Context>
inline void load_partition_list(const pugi::xml_node& root, T& out, Context& context, const std::function<void(const char*)>* report_error, ptrdiff_t* offset_debug);
template<class T, typename Context>
inline void load_vpr_constraints(const pugi::xml_node& root, T& out, Context& context, const std::function<void(const char*)>* report_error, ptrdiff_t* offset_debug);

/* Declarations for internal write functions for the complex types. */
template<class T>
inline void write_partition(T& in, std::ostream& os, const void* data, void* iter);
template<class T>
inline void write_partition_list(T& in, std::ostream& os, const void* data, void* iter);
template<class T>
inline void write_vpr_constraints(T& in, std::ostream& os, const void* data, void* iter);

/* Load function for the root element. */
template<class T, typename Context>
inline void load_vpr_constraints_xml(T& out, Context& context, const char* filename, std::istream& is) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load(is);
    if (!result) {
        int line, col;
        get_line_number(filename, result.offset, &line, &col);
        std::stringstream msg;
        msg << "Unable to load XML file '" << filename << "', ";
        msg << result.description() << " (line: " << line;
        msg << " col: " << col << ")";
        out.error_encountered(filename, line, msg.str().c_str());
    }
    ptrdiff_t offset_debug = 0;
    std::function<void(const char*)> report_error = [filename, &out, &offset_debug](const char* message) {
        int line, col;
        get_line_number(filename, offset_debug, &line, &col);
        out.error_encountered(filename, line, message);
        // If error_encountered didn't throw, throw now to unwind.
        throw std::runtime_error(message);
    };
    out.start_load(&report_error);

    for (pugi::xml_node node = doc.first_child(); node; node = node.next_sibling()) {
        if (std::strcmp(node.name(), "vpr_constraints") == 0) {
            /* If errno is set up to this point, it messes with strtol errno checking. */
            errno = 0;
            load_vpr_constraints(node, out, context, &report_error, &offset_debug);
        } else {
            offset_debug = node.offset_debug();
            report_error(("Invalid root-level element " + std::string(node.name())).c_str());
        }
    }
    out.finish_load();
}

/* Write function for the root element. */
template<class T, typename Context>
inline void write_vpr_constraints_xml(T& in, Context& context, std::ostream& os) {
    in.start_write();
    os << "<vpr_constraints";
    if ((bool)in.get_vpr_constraints_tool_name(context))
        os << " tool_name=\"" << in.get_vpr_constraints_tool_name(context) << "\"";
    os << ">\n";
    write_vpr_constraints(in, os, context);
    os << "</vpr_constraints>\n";
    in.finish_write();
}

typedef const uint32_t __attribute__((aligned(1))) triehash_uu32;
typedef const uint64_t __attribute__((aligned(1))) triehash_uu64;
static_assert(alignof(triehash_uu32) == 1, "Unaligned 32-bit access not found.");
static_assert(alignof(triehash_uu64) == 1, "Unaligned 64-bit access not found.");
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#    define onechar(c, s, l) (((uint64_t)(c)) << (s))
#else
#    define onechar(c, s, l) (((uint64_t)(c)) << (l - 8 - s))
#endif

/* Tokens for attribute and node names. */

enum class atok_t_add_atom { NAME_PATTERN };
constexpr const char* atok_lookup_t_add_atom[] = {"name_pattern"};

enum class atok_t_add_region { SUBTILE,
                               X_HIGH,
                               X_LOW,
                               Y_HIGH,
                               Y_LOW };
constexpr const char* atok_lookup_t_add_region[] = {"subtile", "x_high", "x_low", "y_high", "y_low"};

enum class gtok_t_partition { ADD_ATOM,
                              ADD_REGION };
constexpr const char* gtok_lookup_t_partition[] = {"add_atom", "add_region"};
enum class atok_t_partition { NAME };
constexpr const char* atok_lookup_t_partition[] = {"name"};

enum class gtok_t_partition_list { PARTITION };
constexpr const char* gtok_lookup_t_partition_list[] = {"partition"};
enum class gtok_t_vpr_constraints { PARTITION_LIST };
constexpr const char* gtok_lookup_t_vpr_constraints[] = {"partition_list"};
enum class atok_t_vpr_constraints { TOOL_NAME };
constexpr const char* atok_lookup_t_vpr_constraints[] = {"tool_name"};

/* Internal lexers. These convert the PugiXML node names to input tokens. */
inline atok_t_add_atom lex_attr_t_add_atom(const char* in, const std::function<void(const char*)>* report_error) {
    unsigned int len = strlen(in);
    switch (len) {
        case 12:
            switch (*((triehash_uu64*)&in[0])) {
                case onechar('n', 0, 64) | onechar('a', 8, 64) | onechar('m', 16, 64) | onechar('e', 24, 64) | onechar('_', 32, 64) | onechar('p', 40, 64) | onechar('a', 48, 64) | onechar('t', 56, 64):
                    switch (*((triehash_uu32*)&in[8])) {
                        case onechar('t', 0, 32) | onechar('e', 8, 32) | onechar('r', 16, 32) | onechar('n', 24, 32):
                            return atok_t_add_atom::NAME_PATTERN;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    noreturn_report(report_error, ("Found unrecognized attribute " + std::string(in) + " of <add_atom>.").c_str());
}

inline atok_t_add_region lex_attr_t_add_region(const char* in, const std::function<void(const char*)>* report_error) {
    unsigned int len = strlen(in);
    switch (len) {
        case 5:
            switch (*((triehash_uu32*)&in[0])) {
                case onechar('x', 0, 32) | onechar('_', 8, 32) | onechar('l', 16, 32) | onechar('o', 24, 32):
                    switch (in[4]) {
                        case onechar('w', 0, 8):
                            return atok_t_add_region::X_LOW;
                            break;
                        default:
                            break;
                    }
                    break;
                case onechar('y', 0, 32) | onechar('_', 8, 32) | onechar('l', 16, 32) | onechar('o', 24, 32):
                    switch (in[4]) {
                        case onechar('w', 0, 8):
                            return atok_t_add_region::Y_LOW;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
            break;
        case 6:
            switch (*((triehash_uu32*)&in[0])) {
                case onechar('x', 0, 32) | onechar('_', 8, 32) | onechar('h', 16, 32) | onechar('i', 24, 32):
                    switch (in[4]) {
                        case onechar('g', 0, 8):
                            switch (in[5]) {
                                case onechar('h', 0, 8):
                                    return atok_t_add_region::X_HIGH;
                                    break;
                                default:
                                    break;
                            }
                            break;
                        default:
                            break;
                    }
                    break;
                case onechar('y', 0, 32) | onechar('_', 8, 32) | onechar('h', 16, 32) | onechar('i', 24, 32):
                    switch (in[4]) {
                        case onechar('g', 0, 8):
                            switch (in[5]) {
                                case onechar('h', 0, 8):
                                    return atok_t_add_region::Y_HIGH;
                                    break;
                                default:
                                    break;
                            }
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
            break;
        case 7:
            switch (*((triehash_uu32*)&in[0])) {
                case onechar('s', 0, 32) | onechar('u', 8, 32) | onechar('b', 16, 32) | onechar('t', 24, 32):
                    switch (in[4]) {
                        case onechar('i', 0, 8):
                            switch (in[5]) {
                                case onechar('l', 0, 8):
                                    switch (in[6]) {
                                        case onechar('e', 0, 8):
                                            return atok_t_add_region::SUBTILE;
                                            break;
                                        default:
                                            break;
                                    }
                                    break;
                                default:
                                    break;
                            }
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    noreturn_report(report_error, ("Found unrecognized attribute " + std::string(in) + " of <add_region>.").c_str());
}

inline gtok_t_partition lex_node_t_partition(const char* in, const std::function<void(const char*)>* report_error) {
    unsigned int len = strlen(in);
    switch (len) {
        case 8:
            switch (*((triehash_uu64*)&in[0])) {
                case onechar('a', 0, 64) | onechar('d', 8, 64) | onechar('d', 16, 64) | onechar('_', 24, 64) | onechar('a', 32, 64) | onechar('t', 40, 64) | onechar('o', 48, 64) | onechar('m', 56, 64):
                    return gtok_t_partition::ADD_ATOM;
                    break;
                default:
                    break;
            }
            break;
        case 10:
            switch (*((triehash_uu64*)&in[0])) {
                case onechar('a', 0, 64) | onechar('d', 8, 64) | onechar('d', 16, 64) | onechar('_', 24, 64) | onechar('r', 32, 64) | onechar('e', 40, 64) | onechar('g', 48, 64) | onechar('i', 56, 64):
                    switch (in[8]) {
                        case onechar('o', 0, 8):
                            switch (in[9]) {
                                case onechar('n', 0, 8):
                                    return gtok_t_partition::ADD_REGION;
                                    break;
                                default:
                                    break;
                            }
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    noreturn_report(report_error, ("Found unrecognized child " + std::string(in) + " of <partition>.").c_str());
}
inline atok_t_partition lex_attr_t_partition(const char* in, const std::function<void(const char*)>* report_error) {
    unsigned int len = strlen(in);
    switch (len) {
        case 4:
            switch (*((triehash_uu32*)&in[0])) {
                case onechar('n', 0, 32) | onechar('a', 8, 32) | onechar('m', 16, 32) | onechar('e', 24, 32):
                    return atok_t_partition::NAME;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    noreturn_report(report_error, ("Found unrecognized attribute " + std::string(in) + " of <partition>.").c_str());
}

inline gtok_t_partition_list lex_node_t_partition_list(const char* in, const std::function<void(const char*)>* report_error) {
    unsigned int len = strlen(in);
    switch (len) {
        case 9:
            switch (*((triehash_uu64*)&in[0])) {
                case onechar('p', 0, 64) | onechar('a', 8, 64) | onechar('r', 16, 64) | onechar('t', 24, 64) | onechar('i', 32, 64) | onechar('t', 40, 64) | onechar('i', 48, 64) | onechar('o', 56, 64):
                    switch (in[8]) {
                        case onechar('n', 0, 8):
                            return gtok_t_partition_list::PARTITION;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    noreturn_report(report_error, ("Found unrecognized child " + std::string(in) + " of <partition_list>.").c_str());
}

inline gtok_t_vpr_constraints lex_node_t_vpr_constraints(const char* in, const std::function<void(const char*)>* report_error) {
    unsigned int len = strlen(in);
    switch (len) {
        case 14:
            switch (*((triehash_uu64*)&in[0])) {
                case onechar('p', 0, 64) | onechar('a', 8, 64) | onechar('r', 16, 64) | onechar('t', 24, 64) | onechar('i', 32, 64) | onechar('t', 40, 64) | onechar('i', 48, 64) | onechar('o', 56, 64):
                    switch (*((triehash_uu32*)&in[8])) {
                        case onechar('n', 0, 32) | onechar('_', 8, 32) | onechar('l', 16, 32) | onechar('i', 24, 32):
                            switch (in[12]) {
                                case onechar('s', 0, 8):
                                    switch (in[13]) {
                                        case onechar('t', 0, 8):
                                            return gtok_t_vpr_constraints::PARTITION_LIST;
                                            break;
                                        default:
                                            break;
                                    }
                                    break;
                                default:
                                    break;
                            }
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    noreturn_report(report_error, ("Found unrecognized child " + std::string(in) + " of <vpr_constraints>.").c_str());
}
inline atok_t_vpr_constraints lex_attr_t_vpr_constraints(const char* in, const std::function<void(const char*)>* report_error) {
    unsigned int len = strlen(in);
    switch (len) {
        case 9:
            switch (*((triehash_uu64*)&in[0])) {
                case onechar('t', 0, 64) | onechar('o', 8, 64) | onechar('o', 16, 64) | onechar('l', 24, 64) | onechar('_', 32, 64) | onechar('n', 40, 64) | onechar('a', 48, 64) | onechar('m', 56, 64):
                    switch (in[8]) {
                        case onechar('e', 0, 8):
                            return atok_t_vpr_constraints::TOOL_NAME;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    noreturn_report(report_error, ("Found unrecognized attribute " + std::string(in) + " of <vpr_constraints>.").c_str());
}

/**
 * Internal error function for xs:choice and xs:sequence validators.
 */
[[noreturn]] inline void dfa_error(const char* wrong, const int* states, const char* const* lookup, int len, const std::function<void(const char*)>* report_error);

/**
 * Internal error function for xs:all validators.
 */
template<std::size_t N>
[[noreturn]] inline void all_error(std::bitset<N> gstate, const char* const* lookup, const std::function<void(const char*)>* report_error);

/**
 * Internal error function for attribute validators.
 */
template<std::size_t N>
[[noreturn]] inline void attr_error(std::bitset<N> astate, const char* const* lookup, const std::function<void(const char*)>* report_error);

/* Internal loading functions, which validate and load a PugiXML DOM tree into memory. */
inline int load_int(const char* in, const std::function<void(const char*)>* report_error) {
    int out;
    std::printf("before reading int errno:%d\n", errno);
    out = std::strtol(in, NULL, 10);
    if (errno != 0) {
        std::printf("after reading int errno:%d\n", errno);
        noreturn_report(report_error, ("Invalid value `" + std::string(in) + "` when loading into a int.").c_str());
    }
    return out;
}
inline void load_add_region_required_attributes(const pugi::xml_node& root, int* x_high, int* x_low, int* y_high, int* y_low, const std::function<void(const char*)>* report_error) {
    std::printf("load_add_region_required_attributes errno: %d\n", errno);
    std::bitset<5> astate = 0;
    for (pugi::xml_attribute attr = root.first_attribute(); attr; attr = attr.next_attribute()) {
        atok_t_add_region in = lex_attr_t_add_region(attr.name(), report_error);
        if (astate[(int)in] == 0)
            astate[(int)in] = 1;
        else
            noreturn_report(report_error, ("Duplicate attribute " + std::string(attr.name()) + " in <add_region>.").c_str());
        switch (in) {
            case atok_t_add_region::SUBTILE:
                /* Attribute subtile set after element init */
                break;
            case atok_t_add_region::X_HIGH:
                *x_high = load_int(attr.value(), report_error);
                break;
            case atok_t_add_region::X_LOW:
                *x_low = load_int(attr.value(), report_error);
                break;
            case atok_t_add_region::Y_HIGH:
                *y_high = load_int(attr.value(), report_error);
                break;
            case atok_t_add_region::Y_LOW:
                *y_low = load_int(attr.value(), report_error);
                break;
            default:
                break; /* Not possible. */
        }
    }
    std::bitset<5> test_astate = astate | std::bitset<5>(0b00001);
    if (!test_astate.all()) attr_error(test_astate, atok_lookup_t_add_region, report_error);
}
template<class T, typename Context>
inline void load_add_atom(const pugi::xml_node& root, T& out, Context& context, const std::function<void(const char*)>* report_error, ptrdiff_t* offset_debug) {
    (void)root;
    (void)out;
    (void)context;
    (void)report_error;
    // Update current file offset in case an error is encountered.
    *offset_debug = root.offset_debug();

    for (pugi::xml_attribute attr = root.first_attribute(); attr; attr = attr.next_attribute()) {
        atok_t_add_atom in = lex_attr_t_add_atom(attr.name(), report_error);
        switch (in) {
            case atok_t_add_atom::NAME_PATTERN:
                out.set_add_atom_name_pattern(attr.value(), context);
                break;
            default:
                break; /* Not possible. */
        }
    }

    if (root.first_child().type() == pugi::node_element)
        noreturn_report(report_error, "Unexpected child element in <add_atom>.");
}

template<class T, typename Context>
inline void load_add_region(const pugi::xml_node& root, T& out, Context& context, const std::function<void(const char*)>* report_error, ptrdiff_t* offset_debug) {
    (void)root;
    (void)out;
    (void)context;
    (void)report_error;
    // Update current file offset in case an error is encountered.
    *offset_debug = root.offset_debug();

    for (pugi::xml_attribute attr = root.first_attribute(); attr; attr = attr.next_attribute()) {
        atok_t_add_region in = lex_attr_t_add_region(attr.name(), report_error);
        switch (in) {
            case atok_t_add_region::SUBTILE:
                std::printf("out.set_add_region_subtile errno: %d\n", errno);
                out.set_add_region_subtile(load_int(attr.value(), report_error), context);
                break;
            case atok_t_add_region::X_HIGH:
                /* Attribute x_high is already set */
                break;
            case atok_t_add_region::X_LOW:
                /* Attribute x_low is already set */
                break;
            case atok_t_add_region::Y_HIGH:
                /* Attribute y_high is already set */
                break;
            case atok_t_add_region::Y_LOW:
                /* Attribute y_low is already set */
                break;
            default:
                break; /* Not possible. */
        }
    }

    if (root.first_child().type() == pugi::node_element)
        noreturn_report(report_error, "Unexpected child element in <add_region>.");
}

constexpr int NUM_T_PARTITION_STATES = 2;
constexpr const int NUM_T_PARTITION_INPUTS = 2;
constexpr int gstate_t_partition[NUM_T_PARTITION_STATES][NUM_T_PARTITION_INPUTS] = {
    {0, 0},
    {0, 0},
};
template<class T, typename Context>
inline void load_partition(const pugi::xml_node& root, T& out, Context& context, const std::function<void(const char*)>* report_error, ptrdiff_t* offset_debug) {
    std::printf("load_partition errno: %d\n", errno);
    (void)root;
    (void)out;
    (void)context;
    (void)report_error;
    // Update current file offset in case an error is encountered.
    *offset_debug = root.offset_debug();
    std::printf("load_partition 546 errno: %d\n", errno);
    for (pugi::xml_attribute attr = root.first_attribute(); attr; attr = attr.next_attribute()) {
        std::printf("load_partition 548 errno: %d\n", errno);
        atok_t_partition in = lex_attr_t_partition(attr.name(), report_error);
        std::printf("load_partition 550 errno: %d\n", errno);
        switch (in) {
            case atok_t_partition::NAME:
                out.set_partition_name(attr.value(), context);
                std::printf("load_partition 554 errno: %d\n", errno);
                break;
            default:
                break; /* Not possible. */
        }
    }
    std::printf("load_partition 560 errno: %d\n", errno);

    // Preallocate arrays by counting child nodes (if any)
    size_t add_atom_count = 0;
    size_t add_region_count = 0;
    {
        int next, state = 1;
        for (pugi::xml_node node = root.first_child(); node; node = node.next_sibling()) {
            std::printf("load_partition 568 errno: %d\n", errno);
            *offset_debug = node.offset_debug();
            std::printf("load_partition 570 errno: %d\n", errno);
            gtok_t_partition in = lex_node_t_partition(node.name(), report_error);
            std::printf("load_partition 572 errno: %d\n", errno);
            next = gstate_t_partition[state][(int)in];
            std::printf("load_partition 574 errno: %d\n", errno);
            if (next == -1) {
                dfa_error(gtok_lookup_t_partition[(int)in], gstate_t_partition[state], gtok_lookup_t_partition, 2, report_error);
                std::printf("load_partition 577 errno: %d\n", errno);
            }
            state = next;
            switch (in) {
                case gtok_t_partition::ADD_ATOM:
                    add_atom_count += 1;
                    break;
                case gtok_t_partition::ADD_REGION:
                    add_region_count += 1;
                    break;
                default:
                    break; /* Not possible. */
            }
        }
        std::printf("load_partition 591 errno: %d\n", errno);

        out.preallocate_partition_add_atom(context, add_atom_count);
        std::printf("load_partition 594 errno: %d\n", errno);
        out.preallocate_partition_add_region(context, add_region_count);
        std::printf("load_partition 596 errno: %d\n", errno);
    }
    int next, state = 1;
    for (pugi::xml_node node = root.first_child(); node; node = node.next_sibling()) {
        std::printf("load_partition 600 errno: %d\n", errno);
        *offset_debug = node.offset_debug();
        std::printf("load_partition 602 errno: %d\n", errno);
        gtok_t_partition in = lex_node_t_partition(node.name(), report_error);
        std::printf("load_partition 604 errno: %d\n", errno);
        next = gstate_t_partition[state][(int)in];
        if (next == -1) {
            dfa_error(gtok_lookup_t_partition[(int)in], gstate_t_partition[state], gtok_lookup_t_partition, 2, report_error);
            std::printf("load_partition 608 errno: %d\n", errno);
        }
        state = next;
        switch (in) {
            case gtok_t_partition::ADD_ATOM: {
                std::printf("load_partition 613 errno: %d\n", errno);
                auto child_context = out.add_partition_add_atom(context);
                std::printf("load_partition 615 errno: %d\n", errno);
                load_add_atom(node, out, child_context, report_error, offset_debug);
                std::printf("load_partition 617 errno: %d\n", errno);
                out.finish_partition_add_atom(child_context);
                std::printf("load_partition 619 errno: %d\n", errno);
            } break;
            case gtok_t_partition::ADD_REGION: {
                int add_region_x_high;
                std::printf("load_partition 623 errno: %d\n", errno);
                memset(&add_region_x_high, 0, sizeof(add_region_x_high));
                std::printf("load_partition 625 errno: %d\n", errno);
                int add_region_x_low;
                memset(&add_region_x_low, 0, sizeof(add_region_x_low));
                std::printf("load_partition 628 errno: %d\n", errno);
                int add_region_y_high;
                memset(&add_region_y_high, 0, sizeof(add_region_y_high));
                std::printf("load_partition 631 errno: %d\n", errno);
                int add_region_y_low;
                memset(&add_region_y_low, 0, sizeof(add_region_y_low));
                std::printf("load_partition 634 errno: %d\n", errno);
                load_add_region_required_attributes(node, &add_region_x_high, &add_region_x_low, &add_region_y_high, &add_region_y_low, report_error);
                std::printf("load_partition 636 errno: %d\n", errno);
                auto child_context = out.add_partition_add_region(context, add_region_x_high, add_region_x_low, add_region_y_high, add_region_y_low);
                std::printf("load_partition 638 errno: %d\n", errno);
                load_add_region(node, out, child_context, report_error, offset_debug);
                std::printf("load_partition 640 errno: %d\n", errno);
                out.finish_partition_add_region(child_context);
                std::printf("load_partition 642 errno: %d\n", errno);
            } break;
            default:
                break; /* Not possible. */
        }
    }
    std::printf("load_partition 648 errno: %d\n", errno);
    if (state != 0) {
        dfa_error("end of input", gstate_t_partition[state], gtok_lookup_t_partition, 2, report_error);
        std::printf("load_partition 651 errno: %d\n", errno);
    }
}

constexpr int NUM_T_PARTITION_LIST_STATES = 2;
constexpr const int NUM_T_PARTITION_LIST_INPUTS = 1;
constexpr int gstate_t_partition_list[NUM_T_PARTITION_LIST_STATES][NUM_T_PARTITION_LIST_INPUTS] = {
    {0},
    {0},
};
template<class T, typename Context>
inline void load_partition_list(const pugi::xml_node& root, T& out, Context& context, const std::function<void(const char*)>* report_error, ptrdiff_t* offset_debug) {
    std::printf("load_partition_list errno: %d\n", errno);
    (void)root;
    (void)out;
    (void)context;
    (void)report_error;
    // Update current file offset in case an error is encountered.
    *offset_debug = root.offset_debug();

    if (root.first_attribute())
        noreturn_report(report_error, "Unexpected attribute in <partition_list>.");

    // Preallocate arrays by counting child nodes (if any)
    size_t partition_count = 0;
    {
        int next, state = 1;
        for (pugi::xml_node node = root.first_child(); node; node = node.next_sibling()) {
            *offset_debug = node.offset_debug();
            gtok_t_partition_list in = lex_node_t_partition_list(node.name(), report_error);
            next = gstate_t_partition_list[state][(int)in];
            if (next == -1)
                dfa_error(gtok_lookup_t_partition_list[(int)in], gstate_t_partition_list[state], gtok_lookup_t_partition_list, 1, report_error);
            state = next;
            switch (in) {
                case gtok_t_partition_list::PARTITION:
                    partition_count += 1;
                    break;
                default:
                    break; /* Not possible. */
            }
        }

        out.preallocate_partition_list_partition(context, partition_count);
    }
    int next, state = 1;
    for (pugi::xml_node node = root.first_child(); node; node = node.next_sibling()) {
        *offset_debug = node.offset_debug();
        gtok_t_partition_list in = lex_node_t_partition_list(node.name(), report_error);
        next = gstate_t_partition_list[state][(int)in];
        if (next == -1)
            dfa_error(gtok_lookup_t_partition_list[(int)in], gstate_t_partition_list[state], gtok_lookup_t_partition_list, 1, report_error);
        state = next;
        switch (in) {
            case gtok_t_partition_list::PARTITION: {
                auto child_context = out.add_partition_list_partition(context);
                load_partition(node, out, child_context, report_error, offset_debug);
                out.finish_partition_list_partition(child_context);
            } break;
            default:
                break; /* Not possible. */
        }
    }
    if (state != 0) dfa_error("end of input", gstate_t_partition_list[state], gtok_lookup_t_partition_list, 1, report_error);
}

template<class T, typename Context>
inline void load_vpr_constraints(const pugi::xml_node& root, T& out, Context& context, const std::function<void(const char*)>* report_error, ptrdiff_t* offset_debug) {
    std::printf("load_vpr_constraints errno: %d\n", errno);
    (void)root;
    (void)out;
    (void)context;
    (void)report_error;
    // Update current file offset in case an error is encountered.
    *offset_debug = root.offset_debug();

    for (pugi::xml_attribute attr = root.first_attribute(); attr; attr = attr.next_attribute()) {
        atok_t_vpr_constraints in = lex_attr_t_vpr_constraints(attr.name(), report_error);
        switch (in) {
            case atok_t_vpr_constraints::TOOL_NAME:
                out.set_vpr_constraints_tool_name(attr.value(), context);
                break;
            default:
                break; /* Not possible. */
        }
    }

    std::bitset<1> gstate = 0;
    for (pugi::xml_node node = root.first_child(); node; node = node.next_sibling()) {
        *offset_debug = node.offset_debug();
        gtok_t_vpr_constraints in = lex_node_t_vpr_constraints(node.name(), report_error);
        if (gstate[(int)in] == 0)
            gstate[(int)in] = 1;
        else
            noreturn_report(report_error, ("Duplicate element " + std::string(node.name()) + " in <vpr_constraints>.").c_str());
        switch (in) {
            case gtok_t_vpr_constraints::PARTITION_LIST: {
                auto child_context = out.init_vpr_constraints_partition_list(context);
                load_partition_list(node, out, child_context, report_error, offset_debug);
                out.finish_vpr_constraints_partition_list(child_context);
            } break;
            default:
                break; /* Not possible. */
        }
    }
    std::bitset<1> test_gstate = gstate | std::bitset<1>(0b0);
    if (!test_gstate.all()) all_error(test_gstate, gtok_lookup_t_vpr_constraints, report_error);
}

/* Internal writing functions, which uxsdcxx uses to write out a class. */
template<class T, typename Context>
inline void write_partition(T& in, std::ostream& os, Context& context) {
    (void)in;
    (void)os;
    (void)context;
    {
        for (size_t i = 0, n = in.num_partition_add_atom(context); i < n; i++) {
            auto child_context = in.get_partition_add_atom(i, context);
            os << "<add_atom";
            os << " name_pattern=\"" << in.get_add_atom_name_pattern(child_context) << "\"";
            os << "/>\n";
        }
    }
    {
        for (size_t i = 0, n = in.num_partition_add_region(context); i < n; i++) {
            auto child_context = in.get_partition_add_region(i, context);
            os << "<add_region";
            if (in.get_add_region_subtile(child_context) != NO_SUBTILE)
                os << " subtile=\"" << in.get_add_region_subtile(child_context) << "\"";
            os << " x_high=\"" << in.get_add_region_x_high(child_context) << "\"";
            os << " x_low=\"" << in.get_add_region_x_low(child_context) << "\"";
            os << " y_high=\"" << in.get_add_region_y_high(child_context) << "\"";
            os << " y_low=\"" << in.get_add_region_y_low(child_context) << "\"";
            os << "/>\n";
        }
    }
}

template<class T, typename Context>
inline void write_partition_list(T& in, std::ostream& os, Context& context) {
    (void)in;
    (void)os;
    (void)context;
    {
        for (size_t i = 0, n = in.num_partition_list_partition(context); i < n; i++) {
            auto child_context = in.get_partition_list_partition(i, context);
            os << "<partition";
            os << " name=\"" << in.get_partition_name(child_context) << "\"";
            os << ">";
            write_partition(in, os, child_context);
            os << "</partition>\n";
        }
    }
}

template<class T, typename Context>
inline void write_vpr_constraints(T& in, std::ostream& os, Context& context) {
    (void)in;
    (void)os;
    (void)context;
    {
        auto child_context = in.get_vpr_constraints_partition_list(context);
        os << "<partition_list>\n";
        write_partition_list(in, os, child_context);
        os << "</partition_list>\n";
    }
}

inline void dfa_error(const char* wrong, const int* states, const char* const* lookup, int len, const std::function<void(const char*)>* report_error) {
    std::vector<std::string> expected;
    for (int i = 0; i < len; i++) {
        if (states[i] != -1) expected.push_back(lookup[i]);
    }

    std::string expected_or = expected[0];
    for (unsigned int i = 1; i < expected.size(); i++)
        expected_or += std::string(" or ") + expected[i];

    noreturn_report(report_error, ("Expected " + expected_or + ", found " + std::string(wrong)).c_str());
}

template<std::size_t N>
inline void all_error(std::bitset<N> gstate, const char* const* lookup, const std::function<void(const char*)>* report_error) {
    std::vector<std::string> missing;
    for (unsigned int i = 0; i < N; i++) {
        if (gstate[i] == 0) missing.push_back(lookup[i]);
    }

    std::string missing_and = missing[0];
    for (unsigned int i = 1; i < missing.size(); i++)
        missing_and += std::string(", ") + missing[i];

    noreturn_report(report_error, ("Didn't find required elements " + missing_and + ".").c_str());
}

template<std::size_t N>
inline void attr_error(std::bitset<N> astate, const char* const* lookup, const std::function<void(const char*)>* report_error) {
    std::vector<std::string> missing;
    for (unsigned int i = 0; i < N; i++) {
        if (astate[i] == 0) missing.push_back(lookup[i]);
    }

    std::string missing_and = missing[0];
    for (unsigned int i = 1; i < missing.size(); i++)
        missing_and += std::string(", ") + missing[i];

    noreturn_report(report_error, ("Didn't find required attributes " + missing_and + ".").c_str());
}

inline void get_line_number(const char* filename, std::ptrdiff_t target_offset, int* line, int* col) {
    std::unique_ptr<FILE, decltype(&fclose)> f(fopen(filename, "rb"), fclose);

    if (!f) {
        throw std::runtime_error(std::string("Failed to open file") + filename);
    }

    int current_line = 1;
    std::ptrdiff_t offset = 0;
    std::ptrdiff_t last_line_offset = 0;
    std::ptrdiff_t current_line_offset = 0;

    char buffer[1024];
    std::size_t size;

    while ((size = fread(buffer, 1, sizeof(buffer), f.get())) > 0) {
        for (std::size_t i = 0; i < size; ++i) {
            if (buffer[i] == '\n') {
                current_line += 1;
                last_line_offset = current_line_offset;
                current_line_offset = offset + i;

                if (target_offset < current_line_offset) {
                    if (target_offset < last_line_offset) {
                        throw std::runtime_error("Assertion violation");
                    }

                    *line = current_line - 1;
                    *col = target_offset - last_line_offset;
                    return;
                }
            }
        }

        offset += size;
    }

    *line = current_line;
    *col = target_offset - current_line_offset;
}

} /* namespace uxsd */
