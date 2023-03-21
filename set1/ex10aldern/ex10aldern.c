#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>

#define DAY_DATE 20221103


int main() {
    
    int number;
    
    printf("Personal number: ");
    scanf("%d", &number);
    
    if( DAY_DATE >= number + 180000) {
        printf("ok \n");
    } else {
        printf("!!! NOT OK !!! \n");
    }
    
    return 0;
}

