/*
 *  Program to practise multiplication 
 *
 *  Samples:
 *  - random.c
 */

#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h>
#include <time.h>

#define true = 1;
#define false = 0;

int main(void) {

    int table = 0;
    int answer;
    int n_answers = 0;
    int correct = 0;
    int x;
    

    printf("Practise multiplication!\n");
    printf("Select table (2-9) to train (-1 to quit): ");
    scanf("%d", &table);
    
    srand((unsigned int) time(NULL)); 
    
    while( 1 ) {

        x = rand() % 10;
        n_answers++;
        printf("%d * %d = ", x, table);
        scanf("%d", &answer);
        
        if(answer == -1) {
            break;
        } else if (answer == x * table) {
            printf("Correct! \n");
            correct++;
        } else {
            printf("Sorry, answer was %d! \n", x * table);
        }
        
    }
    printf("Number of questions = %d. Number of correct = %d \n", n_answers, correct);

    return 0;
}




