/*
 *   Calculate the day number given a year, a month and a day.
 *   See : https://www.epochconverter.com/daynumbers
 *   See: https://en.wikipedia.org/wiki/Leap_year#Algorithm
 *
 * Samples:
 */
#include <stdio.h>
//#include <stdbool.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0


// Get ordinal number of day for some date some year
int get_day_nbr(int year, int month, int day);

int check_leap_year(int year);

int days_in_month(int month, bool leap);

// The test method (all tests)
void test();


int main(void) {
    //test();                // <--------- Uncomment to test only

    int year;
    int month;
    int day;

    // -- In ----------------
    printf("Program to calculate to ordinal number of a day\n");
    printf("Input the year > ");
    scanf("%d", &year);
    printf("Input the month number > ");
    scanf("%d", &month);
    printf("Input the day number > ");
    scanf("%d", &day);

    // --- Process ---------

    // This is the top level function
    // Implement it by breaking down into smaller functions
    // Combine to solve the problem
    int dayNbr = get_day_nbr(year, month, day);

    // ---- Out ----
    printf("Ordinal number for %d/%d in %d is: %d\n", day, month, year, dayNbr);

    return 0;
}

int get_day_nbr(int year, int month, int day) {

    int sum = 0;
    bool leap = check_leap_year(year);

    for(int i = 1; i < month; i++) {
        sum += days_in_month(i, leap);
    }

    return sum + day;
}

int check_leap_year(int year) {

    bool leap = false;

    if (year % 4 == 0) {

        if(year % 100 == 0) {
            
            if(year % 400 == 0) {
                leap = true;
            }
        } else {
            leap = true;
        }
    }

    return leap;
}

int days_in_month(int month, bool leap) {

    if( month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;

    } else if (month == 2) {
        if (leap == true) {
            return 29;
        }
        return 28;
    }
    return 31;
}





// TODO Function definitions

#define CHECK_IF_EQUALS(v1, v2) printf((v1) == (v2) ? "ok\n" : "not ok\n")

void test(){
    // TODO
    // CHECK_IF_EQUALS( ...), 31);

    // Etc tests as needed

    exit(0);
}



