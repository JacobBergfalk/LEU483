/*
 *  Finding any common sequences in arrays
 *  This is exercising functional decomposition
 *
 */
#include<stdio.h>
//#include <stdbool.h>
#include <memory.h>

typedef int bool;
#define true 1
#define false 0

#define CHECK_IF_ARR_EQUALS(v1, v2) printf( memcmp(v1, v2, sizeof(v1)) == 0 ? "ok\n" : "not ok\n")

bool is_equal_seq(const int a[], int aStart, const int b[], int bStart, int len);

void copy_seq(  int dest[], const int src[], int start, int end);

void common_seq(int result[], const int a[], const int b[], int size, int seq_len);

void clear_result(int result[], int size);


int main(void) {
    int s1[] = {3, 1, 2, 3, 7, 1, 5};
    int s2[] = {9, 4, 7, 1, 2, 6, 7};
    int s3[] = {1, 2, 3, 4, 7, 3, 8};
    int s4[] = {3, 7, 1, 5, 3, 2, 5};
    int size = 7;
    int result[size];

    int expected1[] = {1, 2, 0, 0, 0, 0, 0};
    common_seq(result, s1, s2, size, 2);
    CHECK_IF_ARR_EQUALS(result, expected1);

    int expected2[] = {0, 0, 0, 0, 0, 0, 0};
    common_seq(result, s1, s2, size, 3);
    CHECK_IF_ARR_EQUALS(result, expected2);

    int expected3[] = {1, 2, 3, 0, 0, 0, 0};
    common_seq(result, s1, s3, size, 3);
    CHECK_IF_ARR_EQUALS(result, expected3);

    int expected4[] = {3, 7, 1, 5, 0, 0, 0};
    common_seq(result, s1, s4, size, 4);
    CHECK_IF_ARR_EQUALS(result, expected4);

}

void common_seq(int result[], const int a[], const int b[], int size, int seq_len) {
    clear_result(result, size);
    
    bool match_found = false;
    int start = 0;
    
    for(int i = 0; i < size; i++) {
        
        for(int j = 0; j < size; j++) {
            
            if(is_equal_seq(a, i, b, j, seq_len) && !match_found) { //!match_found för att ta den första sekvensen
                copy_seq(result, a, i, i + seq_len);
                match_found = true;
            }
        }
    }
    
    if(match_found) start = seq_len;
    
    for(int k = start; k < size; k++) {
        result[k] = 0;
    }
    
    for(int r = 0; r < size; r++) {
        printf("%d", result[r]);
    }
    
}

void copy_seq(int dest[], const int src[], int start, int end) {
    
    int j = 0;
    for(int i = start; i < end; i++) {
        dest[j] = src[i];
        j++;
    }
}

bool is_equal_seq(const int a[], int a_start, const int b[], int b_start, int seq_len) {
    
     bool result = true;

     for(int i = a_start; i < a_start + seq_len; i++) {
         
         if(a[i] != b[b_start]) {
             result = false;
         }
         b_start++;
     }
     
    
    return result;
}

void clear_result(int result[], int size) {
    for (int i = 0; i < size; i++) {
        result[i] = 0;
    }
}
