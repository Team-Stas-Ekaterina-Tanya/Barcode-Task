#include <stdio.h>
#include <stdlib.h>

void roundData(double data[], int size) {
    for (int i = 0; i < size; i++) {
        data[i] = (data[i] >= 0 && data[i] < 0.5) ? 0 : 1;
    }
} 

void printBarcode(double data[], int size) {
    roundData(data, size);
    for (int i = 0; i < size;) {
        for (int j = 0; j < 10; j++) {
            printf("%.lf ", data[i++]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int i, j, n, counter = 0;
    printf("Enter size: \n");
    scanf(" %d", &n); // scanning the size of the array
    double *a = malloc(n * sizeof(double));
    char temp;

    for (i = 0; i < n; i++)
    {
        scanf("%lf%c", &a[i], &temp); // scanning for both the integer and the space(as a character)

        if (temp == '\n') // when temp == enter (\n),i.e, when the user presses enter
        {
            continue;
           
        }
    }
    // for (i = 0; i < n; i++) { // for loop to print the array runs
    //         printf("%.lf ", a[i]);
    //     }
    printBarcode(a, n);
}