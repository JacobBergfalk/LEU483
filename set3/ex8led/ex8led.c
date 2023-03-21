/*
 * Enum and struct types
 *
 * 
 * In this exercise you emulate setting colours to a LED strip with a computer
 * program.
 * 
 * At each position of the LED strip there is a triplet of three (small) LEDS:
 * a red, a green, and a blue LED. For example, switching on only the red and
 * blue LEDs will produce the magenta colour. Other colours are obtained with
 * different combinations of the RGB (red, green, blue) LEDs.
 * 
 * Make use of enumerations and structures to have code easy to read and understand
 *
 * Complete the parts commented with // TODO
 * but read the other comments
 *  
 * Samples:
 *  - enum.c
 *  - struct.c
 * 
 * Note: the main function returns either EXIT_SUCCESS or EXIT_FAILURE
 *          - EXIT_SUCCESS has the value 0
 *          - EXIT_FAILURE has a value different than 0
 *        
 *        If you run the program, it prints this value at the bottom
 *        of the screen. For example, if the return value is EXIT_SUCCESS,
 *        it shows "==== Program exited with exit code: 0 ===="
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define N_POSITIONS 6

// TODO
// Define an enumeration named 'status_t' with values OFF and ON

typedef enum status {
    ON, OFF
} status_t;

// TODO
// Define an enumeration named 'colour_t' with values
// RED, GREEN, BLUE, MAGENTA, CYAN, YELLOW, WHITE, and BLACK

typedef enum colour {
    RED, GREEN, BLUE, MAGENTA, CYAN, YELLOW, WHITE, BLACK
} colour_t;

// TODO
// Define a structure named 'triplet_t' that has the fields red, green, and blue

typedef struct triplet {
    int red;
    int green;
    int blue;
} triplet_t;

// Function to power off all LEDS strip (all positions are BLACK)
void power_off(triplet_t strip[]);

// Function to set a colour to a position in the LED strip
// A colour is set by powering on or off combinations of the RGB LEDs
// Search online 'RGB colour model' if you need help for the RGB combinations
void set_colour(triplet_t strip[], colour_t colour, int position);

int main(){
    // Definitions
    triplet_t strip[N_POSITIONS];
    colour_t white = WHITE;
    colour_t magenta = MAGENTA;
    colour_t yellow = YELLOW;
    int position;

    // TODO
    // Set the colour BLACK to all positions in the LED strip (power off)
    // (Bonus question: is it necessary to make sure the LED strip is off if you
    //                  have not assigned any colour to any position yet?)
    
    // Your code

    // Assert that the LED strip is powered off
    for (int p = 0; p < N_POSITIONS; p++){
        if (strip[p].red != OFF || strip[p].green != OFF || strip[p].blue != OFF){
            printf("Strip is not powered off\n");
            return EXIT_FAILURE;
        }
    }

    // If the strip is not powered off the program will not reach this line
    printf("Strip is powered off\n");

    // TODO
    // Set the white colour to position 2 in the LED strip
    position = 2;

    // Your code

    // Assert that the LED strip has the white colour at position 2
    if(!(strip[position].red == ON && strip[position].green == ON && strip[position].blue == ON)){
        printf("Unexpected colour at position %i\n", position);
        return EXIT_FAILURE;
    }

    // TODO
    // Set the yellow colour to position 4 in the LED strip
    position = 4;

    // Your code

    // Assert that the LED strip has the white colour at position 4
    if(!(strip[position].red == ON && strip[position].green == ON && strip[position].blue == OFF)){
        printf("Unexpected colour at position %i\n", position);
        return EXIT_FAILURE;
    }

    printf("All checks passed\n");

    return EXIT_SUCCESS;
}

// TODO
// Implement the functions here
void power_off(triplet_t strip[]){
    for()
}

void set_colour(triplet_t strip[], colour_t colour, int position){
    // TODO
    // Note: once you have found how to set one colour, the other colours
    //       are obtained by slight modifications of the code
}
