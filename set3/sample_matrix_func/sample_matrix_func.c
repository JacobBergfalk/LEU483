/*
 *   Functions with matrix parameters
 */

#include<stdio.h>
#include<stdbool.h>
#include<memory.h>

#define CHECK_IF_EQUALS(v1, v2) printf((v1) == (v2) ? "ok\n" : "not ok\n")
#define CHECK_IF_ARR_EQUALS(v1, v2) printf( memcmp(v1, v2, sizeof(v1)) == 0 ? "ok\n" : "not ok\n")

#define ROWS 4
#define COLS 4

// Count how many negative values in matrix
// NOTE: Order of parameters must be like this. The rows and cols first!
// NOTE 2: This is C99 not possible in C89.
int countNegatives(int n_rows, int n_cols, const int matrix[][n_cols]);

// Get an array with all the negative values in a matrix
// Result is in negatives
void get_negatives(int negatives[], int n_rows, int n_cols, const int matrix[][n_cols]);


int main(void) {
    // Declare and initialize
    int matrix[ROWS][COLS] = {
            {-1, 0,  -2, 4},
            {0,  1,  -3, 2},
            {8,  -4, -5, 0},
            {5,  7,  -6, 0}
    };

    CHECK_IF_EQUALS(countNegatives(ROWS, COLS, matrix) == 5, false);
    CHECK_IF_EQUALS(countNegatives(ROWS, COLS, matrix) == 6, true);
    CHECK_IF_EQUALS(countNegatives(ROWS, COLS, matrix) == 7, false);


    int n_negatives = countNegatives(ROWS, COLS, matrix);
    int negatives[n_negatives];
    get_negatives(negatives, ROWS, COLS, matrix);
    int expected[] = {-1, -2, -3, -4, -5, -6};
    CHECK_IF_ARR_EQUALS(negatives, expected);

    return 0;
}


int countNegatives(int n_rows, int n_cols, const int matrix[][n_cols]) {
    int count = 0;
    for (int r = 0; r < n_rows; r++) {
        for (int c = 0; c < n_cols; c++) {
            if (matrix[r][c] < 0) {
                count++;
            }
        }
    }
    return count;
}

void get_negatives(int negatives[], int n_rows, int n_cols, const int matrix[][n_cols]) {
    int k = 0;
    for (int r = 0; r < n_rows; r++) {
        for (int c = 0; c < n_cols; c++) {
            if (matrix[r][c] < 0) {
                negatives[k] = matrix[r][c];
                k++;
            }
        }
    }

}