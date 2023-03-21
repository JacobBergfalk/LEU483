#include <stdio.h>
#include <stdlib.h>

int main(void){

   int foundation_year;
   foundation_year = 1829;

   printf("Chalmers was founded in %d.\n", foundation_year);
    

   int year;
   scanf("Insert a year: %d", &year);
   

   if (year == foundation_year){
       printf("%d was when Chalmers was founded.\n\n", year);
   } else {
       printf("In %i Chalmers was not founded.\n\n", year);
   }
   

   // According to the reports, there were this many full-time students in Chalmers
   // - Year 2019:  9,744
   // - Year 2020: 10,203
   // - Year 2021: 10,712
   // The goal of the code below is to present the latest number of students available
   // What is wrong?
   
   int last_year = 2021; // Do not modify this line
   int student_count;
   if (last_year == 2021) {
       student_count = 10712; // Do not modify this line
       last_year = 2020;      // Do not modify this line
   } else if (2020 == last_year){
       student_count = 10203; // Do not modify this line
       last_year = 2019;      // Do not modify this line
   } else if (2019 == last_year){
       student_count = 9744;  // Do not modify this line
       last_year = 2018;      // Do not modify this line
   }
   printf("In the last available report (2021) "); // Do not modify this line
   printf("Chalmers presents it had %d students.\n", student_count); // Do not modify this line

   return 0;
}