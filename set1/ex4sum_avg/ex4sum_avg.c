/*
 *  Sum and Average for n numbers
 *
 *  NOTE: The ending -1 should not be included.
 *
 * Samples:
 * - nested_stmt.c
 */
#include <stdio.h>
//#include <stdbool.h>


int main(void) {
    
    int num, sum;
    int amount_of_num = 0;
    float average;

    printf("Calculate sum and average (-1 to quit)\n");
  
    while ( 1 ) {
        printf("Enter your number: \n");
        scanf("%d", &num);
        
        if(num == -1) {
            break;
        } else { 
            amount_of_num++;
        }
        
        sum = sum + num;
    }
    average = (float) (sum / amount_of_num);
    printf("Sum = %d Avg = %.2f \n", sum, average ); // TODO 

    return 0;
}
