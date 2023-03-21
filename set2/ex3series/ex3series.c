/*
 *   Calculate PI using the Gregory-Leibniz Series
 *   see https://en.wikipedia.org/wiki/Leibniz_formula_for_%CF%80
 *
 * Samples:
 * - series.c
 */
#include <stdio.h>
#include <math.h>

double calculate_pi(int n_terms);


int main(void) {
    int n_terms;
    double pi;

    printf("Calculate PI. How many terms? > ");
    scanf("%d", &n_terms);
    pi = calculate_pi(n_terms);
    printf("PI with %d terms gives %f\n", n_terms, pi);

    return 0;
}


double calculate_pi(int n_terms) {
    
    double answer = 0.0, term;
    long int i;
    
    for(i = 0; i < n_terms; i++) {
        
        term = pow(-1, i)/(2*i + 1);
        answer += term;
        printf("answer: %f \n", answer);
    }
    
    return 4*answer;
}


