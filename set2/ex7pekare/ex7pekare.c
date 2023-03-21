#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include <string.h>


void test(float *a1, float *a2, float *a3) {
    
    //printf("%p \n", a2); För att skriva ut adressen för 

    // printf("%f", *a3 + 3); Skriver ut numret 3, därav positionen i vektorn.

    //a1[2] = *a2; för att printa ut värdet av a

}


int main() {
    // No new code in main allowed
    float a = 2;
    float *b = &a;
    float f[4];
    float *c = &f[3];

    test(f, b, c);

    printf("%.2f\n", f[2]);
}
