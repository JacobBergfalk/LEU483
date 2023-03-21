#include <stdio.h>
#include <math.h>

typedef struct vector {
    double x;
    double y;
    double z;
} vector_t;

double scalar_product2(vector_t *a, vector_t *b);

double scalar_product1(vector_t a, vector_t b);


int main() {
    vector_t p1 = {1, 2, 3};
    vector_t p2 = {1, -2, 3};
    
    double scal1 = scalar_product1(p1, p2);
    double scal2 = scalar_product2(&p1, &p2);
    
    if(fabs(scal1 - scal2) >= 0.001) {
        printf("NOT OK \n");
    } else {
        printf("OK \n");
    }
    
    //printf("scal1: %f , scal2: %f, difference: %f \n", scal1, scal2, scal1 - scal2);
    return 0;
}



double scalar_product1(vector_t a, vector_t b) {
    
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

double scalar_product2(vector_t *a, vector_t *b) {
    return a->x * b->x + a->y * b->y + a->z * b->z;
}

/*
 * 
 */