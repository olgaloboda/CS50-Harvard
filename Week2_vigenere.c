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
    for (int l = 0, len = strlen(argv[1]); l < len; l++) {
        if (isalpha(argv[1][l]) == 0) {
            printf ("Keywords should contain words only\n");
            return 1;
        }
    }
    string p = GetString();
    int key = 0;
    int sum = 0;
    int result = 0;
    int m = 0;
    int j = 0;
    for (int i = 0, n = strlen(p); i < n; i++) {
        if (j < strlen(argv[1])) {
            if (islower (argv[1][j])) {
                key = argv[1][j] - 97;
            }
            else if (isupper (argv[1][j])) {
                key = argv[1][j] - 65;
            }
        } 
        else {
            j = 0;
            if (islower (argv[1][j])) {
                key = argv[1][j] - 97;
            }
            else if (isupper (argv[1][j])) {
                key = argv[1][j] - 65;
            }
        }
         
        if (isalpha (p[i])) {
            if (isupper (p[i])) {
                m = p[i] - 65;
                result = (m + key) % 26;
                sum = 65 + result;
                printf ("%c", sum);
            } 
            if (islower (p[i])) {
                m = p[i] - 97;
                result = (m + key) % 26;
                sum = 97 + result;
                printf ("%c", sum);
            } 
            j++;
        } 
        else {
            printf ("%c", p[i]);
        }
         
    }
    printf ("\n");
}