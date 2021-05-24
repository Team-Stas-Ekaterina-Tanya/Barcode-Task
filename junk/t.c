#include <stdio.h>
#include <stdlib.h>
#define ARR_MAX 128


int main() {
    char c;
    int i = 0, j = 0, n = 0;
    int counter = 0;
    double arr[ARR_MAX];
    char str1[1024];
    char buff[4];
    char *ptr;

    printf("Input n: \n");
    scanf("%d", &n);

    while ((c = getchar()) != EOF && c != 'q') {
        // if ((c >= 48 && c <= 57) || c == '.') {
        //     buff[i] = c;
        //     i++;
        // } 
        // if (c == ' ' || c == '\n') {
        //     buff[i] = '\0';
        //     i = 0;
        //     arr[j] = strtod(buff, &ptr);
        //     counter++;
        // } 
        
    }

    printf("str1: %s\n", str1);

    printf("\n\n\n");
    for (int i = 0; i < n; i++) {
        printf("%.lf ", arr[i]);
    }

    return 0;
}