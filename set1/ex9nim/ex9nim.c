/*
 *  The Nim game, player vs computer
 *  See: https://en.wikipedia.org/wiki/Nim
 *
 *  Samples:
 */

#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#include <time.h>
#define true (1==1)
#define false (!true)

#define PILE_SIZE 13
// human is player = 1 = TRUE

// Get player choice. Force player to enter a number in range 1-3
int get_player_choice(int pile) {
    int amount;
    while (true) {
        printf("Pick coins : ");
        scanf("%d", &amount);
        
        if(amount > 0 && amount < 4) {
            break;
        }
    }
    return amount;
    
}
// Get computer choice. Add some simple AI. I.e if 2 coins left
// computer should pick one, ... make computer a bit smarter than this.
int get_computer_choice(int pile) {
    int amount;
    
    if (pile == 1) {
        amount = 1;
    } else if (pile > 1 && pile <= 4) {
        amount = pile -1;
    } else {
        amount = (rand() % 3) + 1;
    }
    return amount;
}

// After game print a message who won
void game_over_msg(int human_is_player) {
    printf("Game over.\nWinner is: ");
    if (human_is_player == 1) {
        printf("Human \n");
    } else {
        printf("Computer \n");
    }
}


int main(void) {
    srand((unsigned int) time(NULL));

    int pile = PILE_SIZE;
    int n_coins = 0;
    //bool human_is_player = true;
    int turn; // 1 = human

    printf("Welcome to NIM\n");
    printf("There's %d coins in the pile\n", pile);
    
    turn = rand() % 2;
    
    while(pile > 0) {
        
        if(turn == 1) {
            n_coins = get_player_choice(pile);
            printf("Player took %d \n", n_coins);
            turn--;
            
        } else {
            n_coins = get_computer_choice(pile);
            printf("Computer took %d \n", n_coins);
            turn++;
            
        }
        
        pile -= n_coins;
        printf("There's %d coins in the pile\n", pile);
        
    }

    game_over_msg(turn);
    return 0;
}











