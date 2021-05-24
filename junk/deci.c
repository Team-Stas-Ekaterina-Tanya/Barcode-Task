#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define ARR_MAX 128

void error(int pos, char c) {
    fprintf(stderr, "Unwanted character %c at %d\n", c, pos);
    exit(1);
}

int main() {
    double f = 0.;
    int c;
    int initial = 1, final=0;
    int pos = 0;
    double decimal = 0;
    int counter = 0;
    double arr[ARR_MAX];

    while (((c = getchar()) != EOF) && (c != '\n')) {
        pos += 1;
        if (isspace(c)) { // accept spaces before and after the number
            if (initial || final) continue;
            else {
                final = 1;
                continue;
            }
        }
        else if (final) {  // do not accept anything after a space after the number
            error(pos, c);
        }
        initial = 0;     // at least one non blank char
        if (c == '.') {
            if (decimal) { // accept only one decimal dot
                error(pos, c);
            }
            else decimal = 1;
        }
        else if (! isdigit(c)) { // only digits
            error(pos, c);
        }
        else if (decimal == 0) {
            arr[counter] = arr[counter] * 10 + c - '0';   // integer part
        }
        else {
            decimal *= .1;     // fractional part
            arr[counter] += (c - '0') * decimal;
        }
        counter++;
    }
    printf("%.4f\n", arr[0]);

    return 0;
}