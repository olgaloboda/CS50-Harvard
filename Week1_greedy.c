#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void) {
    printf ("Your change: ");
    float change = GetFloat();
    
    while (change < 0) {
        printf ("Your change: ");
        change = GetFloat();
    }
    
    int cents = round ((change) * 100);
    int result = 0;
    int sum = 0;
    
    while (cents - 25 >= 0) {
        result = cents - 25;
        cents = result;
        sum++;
    }
    while (cents - 10 >= 0) {
        result = cents - 10;
        cents = result;
        sum++;
    }
    while (cents - 5 >= 0) {
        result = cents - 5;
        cents = result;
        sum++;
    }
    while (cents - 1 >= 0) {
        result = cents - 1;
        cents = result;
        sum++;
    }
    
    printf ("%d\n", sum);  
}