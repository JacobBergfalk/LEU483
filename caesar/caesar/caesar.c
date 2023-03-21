/*
 *     A program to break Caesar ciphered text
 *
 *     (Read ASSIGNMENT3.txt carefully before you start coding)
 */

// Make sure CodeLite can find the text files used in this assignment 
// Either put the files under the Workspace folder, where Codelite is looking by default
// Or to give the complete path of your file when you open them.

#include <stdio.h>
//#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

// --- Settings in the form of macros

#define TEST false     // If true run tests (only), else run program

#define WORDLIST_FILE    "most_common_1000.txt"   // A file with common words,
                                                  // here called a word list
#define ENCRYPTED_FILE   "encrypted3.txt"         // File with encrypted text. Try
                                                  // also encrypted2 and encrypted3
#define UNCRYPTED_FILE   "out.txt"                // File where uncrypted text
                                                  // will be placed

#define MAX_WLENGTH      20                       // Maximum length of a word
#define MAX_NWORDS       3000                     // Maximum number of text pieces/words


// Structure for world list
typedef struct {
    int nwords;                               // Number of words
    char words[MAX_NWORDS][MAX_WLENGTH + 1];  // Array of strings to hold words
} wlist_t;

// Structure to represent text. The text is divided into text pieces. A piece is either
// a word, or characters between words. Examples on text pieces are "the", ", " and ".".
typedef struct {
    int npieces;                               // Number of text pieces
    char pieces[MAX_NWORDS][MAX_WLENGTH + 1];  // Array of strings to hold text
    int isword[MAX_NWORDS];                    // 1 or 0 to flag if piece is a word or not
} text_t;


// --- Declare functions that could be of interest for main

// Function where all tests are found
void do_tests();

// Reads and analyzes a text file. Result is placed in text_t structure.
void import_text(text_t *T, const char *filename);

// Displays a text on the screen. The first argument can be used to add a description.
void show_text(const char *start_text, const text_t *T);

// Writes the data in a text_t structure to a file.
void export_text(const text_t *T, const char *filename);

// Solves a Caeser ciphred text by brute force. All shifts are applied and result is
// compared to the specified word list. The shift that gives best fit to word list is
// selected as solution nad is applied on the text.
// The shift/key behind the solution is returned.
int solve_cipher(text_t *T);

void print_word(char *word, int rad);


// --- Main
int main(void) {

    if (TEST) {
        do_tests();
        return 0;
    }

    text_t T;
    int key;
    
    import_text(&T, ENCRYPTED_FILE);
    show_text("Encrypted text:\n", &T);
    key = solve_cipher(&T);
    printf("\nKey = %d\n", key);
    show_text("\nDecrypted text:\n", &T);
    export_text(&T, UNCRYPTED_FILE);

    return 0;
}



// --- Functions for handling text files

// Opens a file for reading or writing (depending on selected mode).
// Returns a file pointer.
FILE *open_file(const char *name, const char *mode) {
    FILE *fp;
    fp = fopen(name, mode);
    if (fp == NULL) {
        fprintf(stderr, "Could not open file\n");
        exit(1);
    }
    return fp;
}

void import_text(text_t *T, const char *filename) {
    // Open file for reading
    FILE *fp = open_file(filename, "r");

    // Declare local variables
    char c;                     // Character to be read
    int lpiece = 0;             // Length of present text piece
    bool prev_in_word = false;  // Was last character inside a word?
    bool first_char = true;     // Are we dealing with first character of text?

    // Loop until end of file
    T->npieces = 0;
    while ((c = fgetc(fp)) != EOF) {

        // Do we have a word character?
        bool this_in_word = isalpha(c);

        // Have we moved in or out from a word? If yes, finish text piece and move
        // to next one. Never do this at first character.
        if (!first_char && (prev_in_word != this_in_word)) {
            T->pieces[T->npieces][lpiece] = '\0';
            T->isword[T->npieces] = prev_in_word;
            T->npieces++;
            lpiece = 0;
        }

        // Put character in text structure
        T->pieces[T->npieces][lpiece] = c;
        lpiece++;

        // Update prev_in_word
        prev_in_word = this_in_word;

        // Flag that first character has been done
        first_char = false;
    }

    // Finish last text piece
    T->pieces[T->npieces][lpiece] = '\0';
    T->isword[T->npieces] = prev_in_word;
    T->npieces++;

    // Close file
    fclose(fp);
}

void export_text(const text_t *T, const char *filename) {                       // IMPLEMETERA SJÄLV
    // You implement!!!

    FILE *fp;
    fp = open_file(filename, "w");

    for(int index = 0; index < T->npieces; index++) {

        for(int i = 0; i < strlen(T->pieces[index]); i++) {
            fputc(T->pieces[index][i], fp);
        }
    }

    fclose(fp);
}

void show_text(const char *start_text, const text_t *T) {
    printf("%s", start_text);
    for (int i = 0; i < T->npieces; i++) {
        printf("%s", T->pieces[i]);
    }
}

// --- Character and word sub-functions
// Compares two strings, ignoring case of letters
bool is_same_word(const char *word1, const char *word2) {                       // IMPLEMETERA SJÄLV
    // You implement!!!
    // We can not just simply use strcmp as as lower and upper case
    // shall be treated as equal here.

    if(strlen(word1) != strlen(word2)) return false;
    if(strcasecmp(word1, word2) == 0) return true;
    
    return false;
}

// --- Word list functions
// Reads a word list. Result is placed in wlist_t structure
void import_wlist(wlist_t *W, const char *filename) {                           //IMPLEMETERA SJÄLV
    // You implement!!!
    // In the word list files, there is one word per line. No extra characters.
    // This makes this function much simpler than import_text.
    FILE *fp;
    fp = open_file(filename, "r");

    int line = 0;
    W->nwords = 0;

    while(!feof(fp) && !ferror(fp)) {
        
        if(fgets(W->words[line], MAX_WLENGTH, fp) != NULL) {
            W->words[line][strlen(W->words[line]) -1] = '\0'; 
            line++;
            W->nwords += 1;
            print_word(W->words[line -1 ], line -1);
        }
    }

    fclose(fp);
}

// Checks if a word is in the word list. Returns true or false.
bool is_in_wlist(const wlist_t *W, char *word) {                                    //IMPLEMETERA SJÄLV
    // You implement!!!
    // Here you should make use of is_same_word

    bool found = false;
    int line = 0;

    while(!found && line < W->nwords) {

        if( is_same_word(word, W->words[line])) {
            found = true;
        }
        line++;
    }
    return found;
}

void print_word(char *word, int rad) {
    for(int i = 0; i < strlen(word); i++) {
        printf("%c",word[i]);
    }
    printf("\n");
}



// --- En/decrypt functions

// Applies a Caesar shift on a string. The shift must be >= 0.
void caesar_shift(char *encr, const char *word, int shift) {                        //IMPLEMETERA SJÄLV
    // You implement!!!
    // A hint: Simplest is to handle lower and upper case separately
    int i;
    for(i = 0; i < strlen(word); i++) {
        
        int value = 97;         // for lowercase library, aka small letters
        if(isupper(word[i])) value = 65;    // for uppercase library.

        encr[i] = (word[i] + shift - value) % 26 + value;
    }
    encr[i]='\0';

}
// text_t har n_pieces, pieces[][] och isword[] (1 eller 0 om det är ett ord eller inte )

int solve_cipher(text_t *T) {                                                       // IMPLEMETERA SJÄLV

    wlist_t W;
    import_wlist(&W, WORDLIST_FILE);

    int key = 0;
    int n_hits, best_n_hits = 0;

    for(int k = 0; k < 27; k++) {
        n_hits = 0;
        for(int index = 0; index < T->npieces; index++) {
            if( T->isword[index]) {
                char encrypted[MAX_WLENGTH];
                caesar_shift(encrypted, T->pieces[index], k);
                if(is_in_wlist(&W, encrypted)) n_hits++;
            }
        }
        if(n_hits > best_n_hits) {
            best_n_hits = n_hits;
            key = k;
        }
    }
    
    for(int i = 0; i < T->npieces; i++) {

        if(T->isword[i]) {
            caesar_shift(T->pieces[i], T->pieces[i], key);
        }
        
    }
    
    return key;
}



// --- The function to do all tests

#define CHECK_IF_EQUALS(v1, v2) printf((v1) == (v2) ? "OK\n" : "Not OK !!!\n")

void do_tests() {
    
    // Check comparison of words
    CHECK_IF_EQUALS(is_same_word("fish", "fish"), true);        // ALL OK
    CHECK_IF_EQUALS(is_same_word("fish", "Fish"), true);
    CHECK_IF_EQUALS(is_same_word("fish", "fisk"), false);
    CHECK_IF_EQUALS(is_same_word("fish", "fishes"), false);
    CHECK_IF_EQUALS(is_same_word("fish", ""), false);
    
    //Uncomment to active remaining test
    char word[20];
    
    // Test caesar shifting
    // Shift only allowed to be >= 0, but note that is OK for decryption. If encryption
    // done with shift 3, a shift of 23 gives back the original word
    strcpy(word, "Caesar");
    char encrypted[20];
    
    caesar_shift(encrypted, word, 0);
    CHECK_IF_EQUALS(is_same_word(encrypted, word), true);           // ALL OK
    caesar_shift(encrypted, word, 1);
    CHECK_IF_EQUALS(is_same_word(encrypted, "Dbftbs"), true);
    caesar_shift(encrypted, word, 26);
    CHECK_IF_EQUALS(is_same_word(encrypted, word), true);
    caesar_shift(encrypted, word, 24);
    CHECK_IF_EQUALS(is_same_word(encrypted, "Aycqyp"), true);
    
    // Create a small test word list, and test some word matches
    wlist_t W = {3, {"hello", "dear", "friends"}};
    CHECK_IF_EQUALS(is_in_wlist(&W, "dear"), true);         // ALL OK
    CHECK_IF_EQUALS(is_in_wlist(&W, "Dear"), true);
    CHECK_IF_EQUALS(is_in_wlist(&W, "fish"), false);
    CHECK_IF_EQUALS(is_in_wlist(&W, " "), false);
    
    // Test reading of word list
    import_wlist(&W, "most_common_500.txt");                    //ALL OK
    CHECK_IF_EQUALS(W.nwords, 500);
    CHECK_IF_EQUALS(strcmp(W.words[23], "your"), 0);   // Note that strcmp returns 0 for match
    
    
    // Test exporting of text
    text_t T = {4, {"Hello", " ", "world", "\n"}, {1, 0, 1, 0}};    // ALL OK
    text_t T2;
    export_text(&T, "test.txt");
    import_text(&T2, "test.txt");
    CHECK_IF_EQUALS(T2.npieces, 4);
    CHECK_IF_EQUALS(strcmp(T2.pieces[1], " "), 0);
    CHECK_IF_EQUALS(strcmp(T2.pieces[2], "world"), 0);
    CHECK_IF_EQUALS(T2.isword[0], 1);
    
}


