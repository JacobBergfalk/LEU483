/*
 *  Matrix is an array of arrays, declared like int matrix[][]
 *  
 *  As for arrays index starts at 0.
 *  First index is row, second is column.
 */
#include<stdio.h>

#define ROWS 2
#define COLS 2


int main(void) {
    // Declare ans initialize matrix 
    // Second dimension must be explicitly given (we give both here)
    int matrix[ROWS][COLS] = {
            {1, 2},         // matrix[0] *only* is the first row
            {3, 4}          // matrix[1] *only* is the second row
    };

    printf("%d\n", matrix[0][1]);                // Row 0, column 1, value is 2
    printf("%d\n", matrix[ROWS - 1][COLS - 1]);  // Last position is one less

    // ---------- Changing values ------------------

    matrix[1][0] = 123;   // Row is 1, col is 0
    matrix[1][1]++;
    matrix[0][0]--;

    matrix[0][0] = matrix[1][1];      // Copy bottom right to top left

    int i = 0;
    int j = 1;
    matrix[i][j] = matrix[i + 1][j];    // Copy using variable

    int tmp;
    tmp = matrix[0][1];             // Swapping two values
    matrix[0][1] = matrix[0][0];
    matrix[0][0] = tmp;

    // ---------- Assignment and comparision ----------

    // Can't assign or compare full matrices (same as arrays)

    int matrix2[ROWS][COLS];
    for (int r = 0; r < ROWS; r++) {   // Copy matrix element by element
        for (int c = 0; c < COLS; c++) {
            matrix2[r][c] = matrix[r][c];
        }
    }

    // ---------- IO -------------

    // Print matrix
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            printf("%d ", matrix[r][c]);  // Print one element at the time
        }
        printf("\n");  // Layout
    }

    printf("\n"); // Layout

    printf("Input an integer > ");   // Read into element
    scanf("%d", &matrix[0][0]);
    printf("Value was %d\n", matrix[0][0]);

    return 0;
}


