/*
 *  Using bit operators in C
 *
 *  Samples:
 *  - bit_operators
 *
 *  See also https://en.wikipedia.org/wiki/Bitwise_operations_in_C
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Test macros
#define CHECK_IF_EQUALS(v1, v2) printf( (v1) == (v2) ? "OK\n" : "not OK\n")
#define CHECK_IF_BYTE_EQUALS(s1, s2) printf( (s1 ^ s2) == 0 ? "OK\n" : "not Ok\n")


// A shorter type name (byte_t) for unsigned char (i.e. a byte)
typedef unsigned char byte_t;

// ---------- Declarations --------------

byte_t byte_set_index(byte_t byte, int index);

bool byte_get_index(byte_t byte, int index);

byte_t byte_clear_index(byte_t byte, int index);

byte_t byte_and(byte_t b1, byte_t b2);

bool byte_equals(byte_t b1, byte_t b2);

byte_t byte_or(byte_t b1, byte_t b2);

// Are both bytes true at a common bit
bool byte_intersect(byte_t b1, byte_t b2);


int main(void) {

    CHECK_IF_EQUALS(byte_or(0x00, 0x01), 0x01);
    CHECK_IF_EQUALS(byte_and(0x01, 0x01), 0x01);
    
    CHECK_IF_EQUALS(byte_intersect(0xFA, 0x0A), true);
    CHECK_IF_EQUALS(byte_intersect(0xF0, 0x0F), false);

    CHECK_IF_BYTE_EQUALS(byte_set_index(0x00, 0), 0x01);
    CHECK_IF_BYTE_EQUALS(byte_set_index(0x00, 1), 0x02);
    CHECK_IF_BYTE_EQUALS(byte_set_index(0x00, 2), 0x04);
    
    CHECK_IF_BYTE_EQUALS(byte_get_index(0x0F, 0), true);  // I.e. bit 0 is set to 1
    CHECK_IF_BYTE_EQUALS(byte_get_index(0x0F, 4), false); // Bit 4 is 0

    CHECK_IF_BYTE_EQUALS(byte_clear_index(0xFF, 0), 0xFE);
    CHECK_IF_BYTE_EQUALS(byte_clear_index(0xFF, 1), 0xFD);
    CHECK_IF_BYTE_EQUALS(byte_clear_index(0xFF, 2), 0xFB);
    
    CHECK_IF_EQUALS(byte_equals(0xFA, 0xFA), true);
    CHECK_IF_EQUALS(byte_equals(0xFE, 0xFA), false);

    return 0;
}


// ----------- Implementations of functions ---------------------

byte_t byte_or(byte_t b1, byte_t b2) {
    return b1 | b2;
}

byte_t byte_set_index(byte_t byte, int index) {
    byte_t zero_byte = 0x00;
    return zero_byte | (0x01 << index);
}

bool byte_get_index(byte_t byte, int index) {
    byte_t zero_byte = 0x00;
    return (byte >> index | zero_byte);
}

byte_t byte_clear_index(byte_t byte, int index) {
    return byte & ~(0x01 << index);
}

byte_t byte_and(byte_t b1, byte_t b2) {
    return b1 & b2;
}

bool byte_equals(byte_t b1, byte_t b2) {
    return !(b1 ^ b2);
}

// Are both bytes true at a common bit
bool byte_intersect(byte_t b1, byte_t b2) {
    byte_t zero_byte = 0x00;
    return (b1 & b2) | 0x00;
}





