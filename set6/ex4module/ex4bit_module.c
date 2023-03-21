/*
 *    Implementation of API
 */
#include "ex4bit_module.h"

#include <stdbool.h>

// TODO Paste all implementations to here

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