#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[]) {
    if (argc != 2) {
        printf ("Usage: ./caesar key\n");
        return 1;
    }
    int key = atoi(argv[1]);
    string p = GetString();
    for (int i = 0, n = strlen(p); i < n; i++) {
        int result = 0;
        int j = 0;
        int sum = 0;
        if (isalpha (p[i])) {
            if (isupper (p[i])) {
                j = p[i] - 65;
                result = (j + key) % 26;
                sum = 65 + result;
                printf ("%c", sum);
            }
            else if (islower (p[i])) {
                j = p[i] - 97;
                result = (j + key) % 26;
                sum = 97 + result;
                printf ("%c", sum);
            }
        }
        else {
            printf ("%c", p[i]);
        }
    }
    printf ("\n");
    return 0;
}