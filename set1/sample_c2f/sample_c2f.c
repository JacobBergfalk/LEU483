/*
 *  (this is multi line a comment)
 *
 *  Program to convert Celsius to Fahrenheit
 *
 *  NOTE: The structure of the program, in -> process -> out
 *  That is, program separated in three parts. Don't mix these.
 */
#include<stdio.h>       // Things we need that others have implemented, such as the
                        // functions printf and scanf (included from the standard
                        // input output C library, stdio.h)


// int and void are reserved words. That is, you can't name anything to int or void
int main(void) {   // Program always starts here (at function main)

    float celsius;      // Variable declarations. Variable celsius for real number, used to store input below.
    double fahrenheit;  // NOTE: Content undefined for both variables

    printf("Program to convert Celsius to Fahrenheit\n"); // Print to screen (including a new line \n).

    // ----- Input ----------------

    printf("Input degree C: ");  // Print some help text for user (no newline)
    scanf("%f", &celsius);       // Let user enter a value (program will halt until enter is pressed)
                                        // Input will end up in variable celsius.
                                        // MUST have & before i.e. the address to variable!
                                        // "%f" says: Convert incoming key codes to a float value (each type has a code)

    // -------- Process -----------

    fahrenheit = 9 * celsius / 5 + 32;      // Do the calculation (NOTE: 32 is outside of the division)

    // ----- Output ----------------

    printf("%.2f C = %.2f F\n", celsius, fahrenheit); // Print answer with 2 decimals and a new line (\n).
                                                             // The "f" will be replaces by the char codes for
                                                             // the values of the variables

    return 0; // Send 0 to operating system (= normal termination)
}