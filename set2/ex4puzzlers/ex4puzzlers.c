/*
 *    Loop puzzlers, exercising nested while loops
 *
 *    Will print "patterns"
 *
 *   See:
 *   - puzzlers.c
 *
 */
#include<stdio.h>


int main(void) {

    int i = 0;
    int lines = 7;

    while (i <= lines) {
        int j = 0;
        while(j < i) {
            printf("X");
            j++;
        }
        printf("\n");
        i++;
    }

    printf("\n");    // Layout

    i = 0;
    while(i <= 3) {
        lines = 0;
        int j = 0;

        while(lines <= i) {
            printf(" ");
            lines++;
        }

        while (j <= 10) {
            printf("X");
            j++;
        }
        printf("\n");
        i++;
    }

    return 0;
}