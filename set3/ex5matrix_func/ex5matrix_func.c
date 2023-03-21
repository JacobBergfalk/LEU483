/*
 *  Functions with array parameter(s)
 *
 *  Samples:
 *   - matrix_func.c
 */
#include<stdio.h>
//#include<stdbool.h>
#include<math.h>
#include<memory.h>

typedef int bool;
#define true 1
#define false 0

#define CHECK_IF_EQUALS(v1, v2) printf((v1) == (v2) ? "ok\n" : "not ok\n")
#define CHECK_IF_ARR_EQUALS(v1, v2) printf( memcmp(v1, v2, sizeof(v1)) == 0 ? "ok\n" : "not ok\n")

#define ROWS 3
#define COLS 3

// Count how many elements in matrix greater or equal to limit
int count_gte(int n_rows, int n_cols, const int matrix[n_rows][n_cols], int limit);

// Is the row and col inside the matrix? If so return true else false
bool is_valid_location(int n_rows, int n_cols, int row, int col);


// Convert array to matrix
// Note: array size must be n_rows * n_cols
void array_to_matrix(int n_rows, int n_cols, int matrix[n_rows][n_cols], const int arr[]);

// Sum of all neighbours of position (row, col) in matrix
int sum_neighbours(int n_rows, int n_cols, const int matrix[n_rows][n_cols], int row, int col);


int main(void) {
    int matrix[ROWS][COLS] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
    };


    CHECK_IF_EQUALS(count_gte(ROWS, COLS, matrix, 4), 6);
    CHECK_IF_EQUALS(count_gte(ROWS, COLS, matrix, 9), 1);

    CHECK_IF_EQUALS(is_valid_location(ROWS, COLS, 0, 0), true);
    CHECK_IF_EQUALS(is_valid_location(ROWS, COLS, ROWS - 1, COLS - 1), true);
    CHECK_IF_EQUALS(is_valid_location(ROWS, COLS, -1, 2), false);
    CHECK_IF_EQUALS(is_valid_location(ROWS, COLS, 3, 0), false);

    int m2[2][2];
    int arr2[] = {0, 3, 7, 5};         // Size = 2 * 2
    array_to_matrix(2, 2, m2, arr2);
    int expected2[] = {0, 3};
    CHECK_IF_ARR_EQUALS(m2[0], expected2);
    int expected3[] = {7, 5};
    CHECK_IF_ARR_EQUALS(m2[1], expected3);

    CHECK_IF_EQUALS(sum_neighbours(ROWS, COLS, matrix, 0, 0), 11); // 2+4+5
    CHECK_IF_EQUALS(sum_neighbours(ROWS, COLS, matrix, 1, 1), 40); // 1+2+3+4+6+7+8+9
    CHECK_IF_EQUALS(sum_neighbours(ROWS, COLS, matrix, 2, 2), 19); // 5+6+8

    return 0;
}


// Should use for-loops
int count_gte(int n_rows, int n_cols, const int matrix[n_rows][n_cols], int limit) {
    
    int count = 0;
    for(int r = 0; r < n_rows; r++) {
        for(int c = 0; c < n_cols; c++) {
            
            if(matrix[r][c] >= limit) count++;
            
        }
    }
    return count;
}

bool is_valid_location(int n_rows, int n_cols, int row, int col) {
    
    if(n_rows > row && 0 <= row && n_cols > col && 0 <= col) {
        return true;
    }
    
    return false;
}

// Should use for-loop
void array_to_matrix( int n_rows, int n_cols, int matrix[n_rows][n_cols], const int arr[] ) {
    int count = 0;
    for(int r = 0; r < n_rows; r++) {
        for(int c = 0; c < n_cols; c++) {
            matrix[r][c] = arr[count];
            count++;
        }
    }

}

// Should use for-loops
int sum_neighbours(int n_rows, int n_cols, const int matrix[n_rows][n_cols], int row, int col) {
    
    int sum = 0;
    
    for(int r = row - 1; r <= row + 1; r++) {
        for(int c = col - 1; c <= col + 1; c++) {

            if(is_valid_location(n_rows, n_cols, r, c) && matrix[r][c] != matrix[row][col]) {
                sum += matrix[r][c];
            }
            
        }
    }
    return sum;
    
}


