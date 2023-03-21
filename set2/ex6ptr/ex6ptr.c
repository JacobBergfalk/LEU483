/*
 *  Uncomment a)-i) one at the time and explain
 *
 *  - If compile error: What's the problem (comment out again)?
 *  - If no compile error. Run it. Any problems? If so what happens? Why?
 *    NOTE: if exit code not 0 there's a problem (11 is segmentation fault i.e. crash)
 *  - If no problem what will be printed? Why?
 *
 * Samples
 * - ptr.c
 * - ptr_func.c
 */

#include<stdio.h>

// Try swap values in a and b
void swap(int a, int b);

// Try swap values in a and b using addresses
void swap2(int *a, int *b);


int main(void) {

    int i = 1;
    int j = 2;
    int *k;
    int *l;

    // a)
    //printf("%d", *i );
        // *i är inte deklarerad vilket gör att den inte pekar mot något. variabel i och *i är inte samma sak.

    // b)
    //printf("%d\n", sizeof(&i) == sizeof(i));
        // Storleken av en INT är 4 bytes medan adressen för en variabel är 8 bytes.

    // c)
    //&i = 0xFFFFFF;
        //Adress kan inte bli ändrad på en variabel, detta resulterar i en crash.  

    // d)
    //*&i = 567;
    //printf("%d\n", i);   
        //  *&i == i, print kommer vara 567.

    // e)
    //k = i;
    //printf("%d", *k);
        // här försöker vi ändra på adress till en int. Detta går inte. Rätt sätt är *&k = i;

    // f)
    //*k = i;
    //printf("%d", *k);
        // Går ej. k är en pointer variabel och kan inte ändras till int. 

    // g)
    //*l = &k;
    //printf("%p", l);
        // *l och *k är en pointer variabel, däremot går det inte att ändra från en pointer variabel till adressen av en annan pointer

    // h)
    //swap(i, j);
    //printf("%d %d", i, j);  // Values swapped?
        // värderna ändrade inte värde i huvudfunktionen. Däremot ändrade de sig i void funktionen.

    //i)
    //swap2(&i, &j);
    //printf("%d %d", i, j);  // Values swapped?
        // värderna ändrade värde i och med att pekarna bytte motiv att peka på.

    return 0;
}


// ----------- Methods -----------------

// Try to swap the values of a and b
void swap(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// Another try ...
void swap2(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
