/*
 *  A first exercise involving functions.
 *  Macros for testing are also introduced.
 *
 *  If you haven't seen the lecture yet, take 
 *  a look at e.g.:
 *  	- Chapter 6 (p 101) in the book "C från början"
 *  	- https://www.learn-c.org/en/Functions
 *  	- https://sv.wikibooks.org/wiki/C-programmering#Funktioner
 *
 *  Samples:
 *  - functions.c
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Test macros
// CHECK_IF_EQUALS will print ok if v1 and v2 are equal
#define CHECK_IF_EQUALS(v1, v2) printf((v1) == (v2) ? "ok\n" : "not ok\n")
// CHECK_IF_EPS_EQUALS will print ok if difference of v1 and v2 is less than 0.0001
#define CHECK_IF_EPS_EQUALS(v1, v2) printf(fabs((v1) - (v2)) < 0.0001 ? "ok\n" : "not ok\n")

#define PI 3.1415926

// ------------- Function declarations -------------

int square(int i) {
    return i*i;
}

float avg(float i, float j, float k) {
    return (i + j + k)/3;
}

float rectangle(float width, float height) {
    return width * height;
}

float deg_to_rad(float deg) {
    return deg * PI / 180;
}

int absolute(int i) {
    if (i < 0) {
        i = i * -1;
    } 
    return i;
}

long long factorial(int n) {
    long long factorial = 1;
    while (n != 0) {
        factorial = factorial * n;
        n--;
    }
    return factorial;
}

int pow_int(int base, int exp) {
    return pow(base, exp);
}

int digit_sum(int number) {
    int sum = 0; 
    int temp;
    
    while (number > 0) {
        temp = number % 10;
        sum = sum + temp;
        number = number/10;
    }
    printf("%d", sum);
    return sum;
}

/*
 *  Just testing the functions not a meaningful program
 */
int main(void) {

    // TODO This should print ok
    //CHECK_IF_EQUALS(square(4), 16);
    //CHECK_IF_EQUALS(square(-2), 4);

    // TODO Uncomment one at a time, all should print ok
    
    //CHECK_IF_EPS_EQUALS(avg(1.0, 1.0, 1.0), 1.0);   // Average is 1.0
    //CHECK_IF_EPS_EQUALS(avg(1.5, 2.0, 4.0), 2.5);
    /*
    CHECK_IF_EPS_EQUALS(rectangle(4.0, 5.0), 20.0);
    CHECK_IF_EPS_EQUALS(rectangle(33.3, 3.0), 99.9);
    
    CHECK_IF_EPS_EQUALS(deg_to_rad(0), 0);
    CHECK_IF_EPS_EQUALS(deg_to_rad(90), 1.5708);

    CHECK_IF_EQUALS(absolute(12), 12);      // Absolute of 12 is 12
    CHECK_IF_EQUALS(absolute(0), 0);
    CHECK_IF_EQUALS(absolute(-4), 4);
    
    CHECK_IF_EQUALS(factorial(1), 1);
    CHECK_IF_EQUALS(factorial(3), 6);
    CHECK_IF_EQUALS(factorial(15), 1307674368000);  // Need long long for result!

    CHECK_IF_EQUALS(pow_int(2, 4), 16);
    CHECK_IF_EQUALS(pow_int(1, 23), 1);
    CHECK_IF_EQUALS(pow_int(4, 0), 1);
    */
    CHECK_IF_EQUALS(digit_sum(11111), 5);
    CHECK_IF_EQUALS(digit_sum(12345), 15);
    
    return 0;
}
