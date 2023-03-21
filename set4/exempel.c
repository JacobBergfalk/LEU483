#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<memory.h>

int main(void) {


    // en while loop är till för att skapa en loop som återupprepar koden innuti {} tills while-loopens vilkor är mötta.
    // ex på detta
    //(ta bort "/*" och "*/" för att testa) (kom ihåg att ta tillbaks /* och */ efter du har testat varje whileloop)
    int x = 1;
    /*

    while(x < 10) {
        printf("%d \n", x);
        x++;
    }

    */

    // Det går även att göra en evighetsloop med en whileloop genom att skaffa ett vilkor som inte går att möta.
    //Ex
                    // i detta fall är det på grund av att x aldrig blir ett större tal och behåller sitt värde från 
    /*
    while(x < 10) {
        printf("%d \n", x);
    }
    */

   // eller

    /*
   while(true) {
        printf("%d \n", x);
        x++;                        // oavsett om du ökar x så kommer den inte sluta.
   }
    */

   // Den här typen av whileloop är det tänkt att använda i Bulls and cows. 
   // det går att bryta en oändlig loop med en "break;"
   // EX


    /*
    while(true) {

        printf("Skriv ett tal");
        scanf("%d", &x);

        if( x == -1) {                   // i det här fallet avslutas loopen om man matar in -1
            break;  
        }
    }
    */

    // I bulls and cows ska du använda dig av break; vid de tillfällen och nummer du ska avsluta programmet. 
    // t.ex med aborted. 
    // if (input == -1) {
    //      aborted = true;
    //      break;
    // }

   return 0;
} 

