/*
 *     A small program to analyse text in a file
 *
 *     (Read ASSIGNMENT3b.txt carefully before you start coding)
 */

// Make sure CodeLite can find the text files used in this assignment 
// Either put the files under the Workspace folder, where Codelite is looking by default
// Or to give the complete path of your file when you open them.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// --- Settings

#define TEST true                       // If true run tests (only), else run program

const char INPUT_FILE[] = "sherlock.txt"; // Name of file to analyse
const int MAX_LINELENGTH = 500;           // Max number of characters in one line of file
const int NLETTERS = 'z' - 'a' + 1;       // Numbers of letters we handle


// This time main is placed at the end

// --- Sub-functions

// Opens a file for reading
// Returns a file pointer.
// Error if the file cannot be opened
FILE *open_file(const char *name) {
    FILE *fp;
    fp = fopen(name, "r");
    if (fp == NULL) {
        fprintf(stderr, "Could not open file\n");
        exit(1);
    }
    return fp;
}

// Reads one line from the file (up to length of MAX_LINELENGTH)
// Returns true if EOF reached, or any error while reading
// Any '\n' is removed from the line
bool read_one_fileline(char s[], FILE *fid) {
    // You add the code
}

// Returns the number of words in the string
// Numbers such as 23 is not treated as a word
int nwords_in_string(const char *s) {

    int n_words = 1;
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] == ' ' && isalpha(s[i + 1])) {
            n_words++;
        }
    }

    return n_words;

}

// Sets all values in an integer array to 0
void zero_int_array(int a[], int n) {
    // You add the code
}

// Sums the values in an integer array
int sum_int_array(const int a[], int n) {
    // You add the code
}

// Counts the usage of letters in the string
// The counts are added the array letter_usage.
// Number of 'a'-s added to letter_usage[0] etc.
void append_letter_usage(int letter_usage[], const char *s) {
    // You add the code
}



// --- The function to do all tests
#define CHECK_IF_EQUALS(v1, v2) printf((v1) == (v2) ? "OK\n" : "Not OK !!!\n")
void do_tests() {
    // As usual, uncomment the tests one at the time
    /*
    // Test reading a file to its end
    {
        char testfile[] = "test.txt";
        char s[MAX_LINELENGTH];
        bool eof_reached = false;
        FILE *fid = open_file(testfile);
        for (int i = 0; !eof_reached; ++i) {
            eof_reached = read_one_fileline(s, fid);
            // We check that the first and last lines come out OK
            if (i == 0)
                CHECK_IF_EQUALS(strcmp(s, "Line 1"), 0);
            else if (i == 4)
                CHECK_IF_EQUALS(strcmp(s, "A last line"), 0);
        }
        fclose(fid);
    }

    char s1[] = "This is a string to be used for testing";
    char s2[] = "We found 38 apples, two lemons and 23 bananas";
    char s3[] = "Can't help falling in love in fine-tuning";

    CHECK_IF_EQUALS(nwords_in_string(s1), 9);
    CHECK_IF_EQUALS(nwords_in_string(s2), 7);
    CHECK_IF_EQUALS(nwords_in_string(s3), 7);

    int letter_usage[NLETTERS];
    zero_int_array(letter_usage, NLETTERS);

    append_letter_usage(letter_usage, s1);
    CHECK_IF_EQUALS(letter_usage[0], 1);
    CHECK_IF_EQUALS(letter_usage['e' - 'a'], 3);
    append_letter_usage(letter_usage, s2);
    CHECK_IF_EQUALS(letter_usage[0], 6);
    CHECK_IF_EQUALS(letter_usage['e' - 'a'], 6);
     */
}


// --- Main
int main(void) {

    if (TEST) {
        do_tests();
        return 0;
    }

    // You add code

    return 0;
}
