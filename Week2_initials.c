#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(void) {
    string s = GetString();
    int k = 0;
    if (s != NULL) {
        for (int i = 0, n = strlen(s); i < n; i++) {
            if (s[i] != ' ' && k != 1) {
                printf ("%c", toupper(s[i]));
                k = 1;
            }
            if (s[i] == ' ') {
                printf ("");
                k = 0;
            }
        }
    }
    printf ("\n");
}