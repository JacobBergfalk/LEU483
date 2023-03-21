/*
 *    Testing the bit set module
 */
#include <stdio.h>
#include <stdbool.h>
#include "ex4bit_module.h" // Paste in text of ex4bit_module.h, types and function declarations
// MENAR DOM ATT INCLUDE ex4bit_module.c ????????!!?!??!?!!?!??!!??! ?WTF 
// Test macros
#define CHECK_IF_EQUALS(v1, v2) printf( (v1) == (v2) ? "ok\n" : "not ok\n")
#define CHECK_IF_BYTE_EQUALS(s1, s2) printf( (s1 ^ s2) == 0 ? "ok\n" : "not ok\n")


void main() {

    // All declared in ex4bit_module.h
    CHECK_IF_EQUALS(byte_and(0x01, 0x01), 0x01);
    CHECK_IF_EQUALS(byte_or(0x00, 0x01), 0x01);
    
    CHECK_IF_EQUALS(byte_intersect(0xFA, 0x0A), true);
    CHECK_IF_EQUALS(byte_intersect(0xF0, 0x0F), false);

    CHECK_IF_BYTE_EQUALS(byte_set_index(0x00, 0), 0x01);
    CHECK_IF_BYTE_EQUALS(byte_set_index(0x00, 1), 0x02);
    CHECK_IF_BYTE_EQUALS(byte_set_index(0x00, 2), 0x04);

    CHECK_IF_BYTE_EQUALS(byte_get_index(0x0F, 0), true);
    CHECK_IF_BYTE_EQUALS(byte_get_index(0x0F, 4), false);

    CHECK_IF_BYTE_EQUALS(byte_clear_index(0xFF, 0), 0xFE);
    CHECK_IF_BYTE_EQUALS(byte_clear_index(0xFF, 1), 0xFD);
    CHECK_IF_BYTE_EQUALS(byte_clear_index(0xFF, 2), 0xFB);

    CHECK_IF_EQUALS(byte_equals(0xFA, 0xFA), true);   
    CHECK_IF_EQUALS(byte_equals(0xFE, 0xFA), false);
}
