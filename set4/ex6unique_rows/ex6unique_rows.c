/*
 *   How many unique rows in a matrix?
 */
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define ROWS 4
#define COLS 4

#define CHECK_IF_EQUALS(v1, v2) printf((v1) == (v2) ? "ok\n" : "not ok\n")

int unique_rows(int n_rows, int n_cols, const int matrix[][n_cols]);

bool row_match(int row, int n_rows, int n_cols, const int matrix[][n_cols]);

void print_arr(const int *arr, int size);


int main(void) {
    int m1[ROWS][COLS] = {
            {7, 1, 3, 6},
            {6, 2, 7, 1},
            {8, 9, 1, 3},
            {5, 6, 9, 1},
    };
    int m2[ROWS][COLS] = {
            {7, 1, 3, 9},
            {6, 9, 7, 1},
            {7, 1, 3, 9},
            {7, 1, 3, 9},
    };


    CHECK_IF_EQUALS(unique_rows(ROWS, COLS, m1) == 4, true);
    CHECK_IF_EQUALS(unique_rows(ROWS, COLS, m2) == 2, true);

    return 0;
}


int unique_rows(int n_rows, int n_cols, const int matrix[][n_cols]) {
    

    // matcha en rad med alla andra och se om de matchar
    // om de matchar unique = 4 - 1
    int unique = 4;
    for(int r = 0; r < n_rows; r++) {

        
    }

}

bool row_match(int row, int n_rows, int n_cols, const int matrix[][n_cols]) {

    bool match;
    int unique = 0;

    for(int r = 0; r < n_rows; r++) {
        match = true;
        for(int c = 0; c < n_cols; c++) {

            if(matrix[row][c] != matrix[r][c]) {
                match = false;
            }
        }

        if(!match) {
            unique++;
        }


    }


    for(int c = 0; c < n_cols; c++) {

        if(matrix[0][c] != matrix[row][c]) {
            match = false;
        }
    }

    return match;
}



// TODO Definitions of helper methods

// ----------- Helper method -----------------

void print_arr(const int arr[], int size) {
    printf("[");
    for (int i = 0; i < size - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[size - 1]);
}