#include "../inc/HelperFunctions.h"

int findCSymbol(int *arr, int n) {
    int sum = 0;

    for(int i = 1, j = 0; i <= n, j < n; i++, j++) { 
        sum += ((n - i) % 10 + 1) * arr[j];
    }

    return (sum %= 11);
}

int findKSymbol(int *arr, int n) {
    int sum = 0;
    
    for(int i = 1, j = 0; i <= n + 1 , j < n + 1; i++, j++) {
        sum += ((n - i + 1) % 9 + 1) * arr[j];
    }

    return (sum %= 11);
}
