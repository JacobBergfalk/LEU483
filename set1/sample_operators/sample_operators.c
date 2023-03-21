/*
 *       Arithmetic and Logical operators
 */
#include <stdio.h>

int main(void) {


    // ------ Arithmetic ops ------------------

    printf("4 + 3 = %d\n", 4 + 3);
    printf("4 - 3 = %d\n", 4 - 3);
    printf("4 * 3.0 = %lf\n", 4 * 3.0); // Mixing types ok (double and int). NOTE result double
    printf("14 / 3 = %d\n", 14 / 3);   // NOTE: Integer division!!!
    printf("14 %% 3 = %d\n", 14 % 3);   // Remainder
    printf("-4 = %d\n", -4);       // Negation

    // Real division, must cast (change type) of value to float or double
    printf("%lf\n", 14.0 / 3);        // 14.0 is of type double ... or
    printf("%lf\n", (float) 14 / 3);  // ...cast 14 to 14.000000 (approx) ... or
    printf("%lf\n", (double) 14 / 3); // ...cast 14 to 14.0000000000000 (approx)

    // ---- Comparision and logical ops -------------------

    // NOTE: that value 0 represents false, all other (also negative) are true.

    printf("4 == 3 gives %d\n", 4 == 3);    // NOTE: Two '=' for logical equals !!!
    printf("4 != 3 gives %d\n", 4 != 3);    // Not equals
    printf("4 > 3 gives %d\n", 4 > 3);     // Bigger than
    printf("4 >= 3 gives %d\n", 4 >= 3);    // Bigger equals than
    printf("4.0 < 3 gives %d\n", 4.0 < 3);   // Mixing types ok (double and int)
    printf("4 <= 3.0 gives %d\n", 4 <= 3.0);


    int i = 5;
    printf("Input an integer > ");
    scanf("%d", &i);
    // NOTE: How to write interval!
    printf("i is in interval ]1-5[ %d\n", 1 < i && i < 5);     // Logical and &&
    printf("i is in interval [1-5] %d\n", 1 <= i && i <= 5);
    printf("i is outside interval [1-5] %d\n", i < 1 || 5 < i); // Logical or ||
    printf("i is outside interval ]1-5[ %d\n", i <= 1 || 5 <= i);
    printf("i is outside interval ]1-5[ %d\n", !(1 < i && i < 5));

    // --- Increment/decrement --------

    // For ++ and -- , see variables.c

    return 0;
}