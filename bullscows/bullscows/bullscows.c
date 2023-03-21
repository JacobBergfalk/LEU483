/*
 *     The bulls and cows game
 *
 *     (Read ASSIGNMENT1.txt carefully before you start coding)
 *
 *     NOTE: Only int's, if, while and functions needed!
 */

#include <stdio.h>
//#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define TEST false     // If true run tests (only), else run program, change to "false" only after implementing functions
#define DEBUG false    // If true, print number to guess to make debugging easier

typedef int bool;
#define true 1
#define false 0

// ----------- Declare functions used in main ----------

int get_random_4digit();
int get_digit_at_position(int number, int position);
int n_digits(int guess);
bool digit_is_in(int number, int digit);
int count_bulls(int guess, int answer);
int count_cows_and_bulls(int guess, int answer);
int get_player_guess();
void test();

/*
 *  Program starts here
 */
int main(void) {
  
    srand((unsigned int) time(NULL));     // Init random number generator

    int guess = 0, bulls = 0, cows = 0, try_again;

    while(true) {
        
        bool aborted = false;
        int n_guess = 0;
        
        printf("Welcome to Bulls and Cows\n");
        printf("Try to guess a 4 digit number with digits 1-9\n");
        printf("and no repeating digits (-1 to abort).\n\n");
        printf("Bulls = correct digit(s) in correct positions.\n");
        printf("Cows = correct digit(s).\n\n");

        int answer = get_random_4digit();
        

        while(!aborted) {
            //printf("Answer: %d \n", answer);
            guess = get_player_guess();
            n_guess++;

            if (guess == -1) {
                aborted = true;
                break;
            } 

            if (n_digits(guess) != 4) {
                printf("Please guess a 4-digit number without zeros.");
                guess = get_player_guess();
            }

            bulls = count_bulls(guess, answer);
            cows = count_cows_and_bulls(guess, answer) - bulls;

            if(bulls == 4) {
                break;
            }
            printf("%d \n", answer);
            printf("There are %d bulls and %d cows \n", bulls, cows);
        }

        if (aborted) {
            printf("Game aborted\n");
        } else {
            printf("Done, number was %d and you needed %d guesses\n", answer, n_guess);
        }

        printf("Select 0 or 1 to quit game or to play again:");
        scanf("%d", &try_again);
        if(try_again == 0) {
            break;
        }
    }

    return 0;
}



int get_random_4digit() {
    
    int num, answer = 0, power = 1000;

    while(true) {
        int count = 1;
        num = rand() % 9 + 1;
        while(count <= 4) {

            if(num == get_digit_at_position(answer, count)) {
                num = rand() % 9 + 1;
                count = 0;
            }
            count++;
        }
        
        answer = answer + num * power;
        power /= 10;

        if(power <= 0) {
            break;
        }
    }
    printf("%d", answer);
    return answer;
}

int get_digit_at_position(int number, int position) {

    int count = 1;

    while(number != 0) {

        if (count == position) {
            return number % 10;
        }
        number /= 10;
        count++;
    }

    return 0;
}

int n_digits(int guess) {
    
    int count = 0;
    
    while (guess != 0) {
        
        guess /= 10;
        count++;
    }
    return count;
}

bool digit_is_in(int number, int digit) {
    
    while(number != 0) {

        if (number % 10 == digit) {
            return true;
        }
        number /= 10;
    }
    
    return false;
}


// Returns number of bulls in guessed number
int count_bulls(int guess, int answer) {
    
    int bulls = 0;

    while(guess != 0 && answer != 0) {
        
        if (guess % 10 == answer % 10) {
            bulls++;
        }
        
        guess /= 10;
        answer /= 10;
    }
    
    return bulls;
}

// Returns number of bulls and cows in guessed number
// Comment: Counting both bulls and cows together is simpler to implement,
// instead of just counting cows. The number of cows you get by combining
// this function and count_bulls
int count_cows_and_bulls(int guess, int answer) {

    int total = 0;

    while (guess != 0) {

        if(digit_is_in(answer, guess % 10)){
            total++;
        }
        guess /= 10;

    }
    return total;
}

// Get input from player
int get_player_guess() {
    int guess;
    printf("Guess > ");
    scanf("%d", &guess);
    return guess;
}
