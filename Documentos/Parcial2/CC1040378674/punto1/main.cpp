#include <cstdio>
#include <cstdlib>

#include "circular.h"
#include "spiral.h"

void test_circular();
void test_spiral();

int main(){
    test_circular();
    test_spiral();

    return 0;
}

void test_circular(){
    printf("Test a la clase Circular\n");

    Circular circular;

    circular.set_radius(1);
    circular.set_time(1);
    circular.set_dt(0.1);
    circular.set_angular_frequency(5);

    circular.move_and_track("prueba1.txt");

    double *x, *y;

    int length = circular.move_and_track(x, y);

    for (int i = 0; i < length; i++){
        printf("%f %f\n", x[i], y[i]);
    }

    free(x);
    free(y);
}

void test_spiral(){
    printf("Test a la clase Spiral\n");

    Spiral spiral;

    spiral.set_radius(1);
    spiral.set_vz(3);
    spiral.set_time(1);
    spiral.set_dt(0.1);
    spiral.set_angular_frequency(5);

    spiral.move_and_track("prueba2.txt");

    double *x, *y, *z;

    int length = spiral.move_and_track(x, y, z);

    for (int i = 0; i < length; i++){
        printf("%f %f %f\n", x[i], y[i], z[i]);
    }

    free(x);
    free(y);
    free(z);
}
