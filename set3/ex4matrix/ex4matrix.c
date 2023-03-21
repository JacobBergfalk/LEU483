/*
 *     Read, transpose and print a matrix
 *
 *  Samples:
 *  - matrix.c
 */
#include<stdio.h>

#define ROWS 2   // Possibly try other values
#define COLS 2


int main(void) {
    int matrix[ROWS][COLS];
    int transpose[COLS][ROWS];

    // --- In -------------
    printf("Program to transpose matrix\n");
    
    int num;
    
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            
            printf("Input %d %d > ", i, j);
            scanf("%d", &num );
            matrix[i][j] = num;
        }
    }

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
    // ------ Out ------------------

    printf("Matrix is\n");
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            printf("%d ", matrix[r][c]);
        }
        printf("\n");
    }

    printf("Transpose is\n");
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            printf("%d ", transpose[r][c]);
        }
        printf("\n");
    }

    return 0;
}
