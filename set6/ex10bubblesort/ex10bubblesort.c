#include <stdio.h>
#include <stdbool.h>

int main() {
    double f[] = {3.4, -1.1, -5.3, 2.3, 0, -0.23, 1.11};
    const int n = sizeof(f) / sizeof(f[0]);
    bubble_sort(f, n);
    printf("%.2f\n", f[0]); // This shall print -5.30
    printf("%.2f\n", f[n - 1]); // This shall print 3.40
}