/*
 *  Fiddling with int's, move digits around etc.
 *
 *  HINT: Heavy use of % (modulo = remainder) and / (integer division)
 *
 *  Samples:
 *  - functions.c
 *  - operators.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <stdbool.h>

#define true 1
#define false 0
// Test macros
#define CHECK_IF_EQUALS(v1, v2) printf((v1) == (v2) ? "ok\n" : "not ok\n")

// --------------- Function declarations ------------------------

// How many digits in number?
int n_digits(int number) {
    int count = 0;
    while (number != 0) {
        
        number /= 10;
        count++;
    }
    return count;
}

// Is the digit in this number?
int digit_is_in(int number, int digit) {
    
    int temp;
    while(number != 0) {
        
        temp = number % 10;
        if (temp == digit) {
            return true;
        }
        number /= 10;
    }
    
    return false;
}

// Get digit for the position (positions start at 1, from right)
int get_digit_at_position(int number, int position) {
    
    int count = 1;
    int temp;
    
    while(number != 0) {
        
        if (count == position) {
            return number % 10;
        }
        number /= 10;
        count++;
    }
    
    return false;
}

// Swap two digits in a number using position like above
int swap(int number, int from_position, int to_position) {
    
    double new_num;
    int position = n_digits(number);
    
    if(from_position == to_position) {
        return number;
    }
    
    new_num = new_num + get_digit_at_position(number, from_position) * pow(10, to_position -1);
    new_num = new_num + get_digit_at_position(number, to_position) * pow(10, from_position -1);
    
    while(position != 0) {
        
        if(position != from_position && position != to_position) {
            new_num = new_num + get_digit_at_position(number, position) * pow(10, position -1);
        }
        position--;
    }
    
    return new_num;
}

int main(void) {

    // TODO Uncomment one at a time, all should print ok
    
    CHECK_IF_EQUALS(n_digits(123), 3);   // 123 has 3 digits
    CHECK_IF_EQUALS(n_digits(12345), 5);
    CHECK_IF_EQUALS(n_digits(1023945), 7);
    
    CHECK_IF_EQUALS(digit_is_in(2637, 2), true);   // Yes 2 is in 2637
    CHECK_IF_EQUALS(digit_is_in(263785, 4), false);  // No 4 is not in 263785
    
    CHECK_IF_EQUALS(get_digit_at_position(4321, 1), 1);   // Digit at position 1 is 1
    CHECK_IF_EQUALS(get_digit_at_position(12345, 3), 3);
    CHECK_IF_EQUALS(get_digit_at_position(12345678, 4), 5);
    
    CHECK_IF_EQUALS(swap(12345, 2, 3), 12435);     // Swap position 2 and 3.
    CHECK_IF_EQUALS(swap(123456, 1, 5), 163452);
    CHECK_IF_EQUALS(swap(12345678, 4, 4), 12345678);
    CHECK_IF_EQUALS(swap(12345678, 3, 8), 62345178);
    
    return 0;
}




