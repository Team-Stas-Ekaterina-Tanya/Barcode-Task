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

const char decodeSymbol(char *str) {
    int i;
    char buff;
    char *arr[] = {"00001", "10001", "01001", "11001", "00101", "10100", "01100", "00011", "10010", "10000", "00100", "00110"};

    for (i = 0; i <= 11; i++) {
        if (!(strcmp(str, arr[i]))) {
            if (i < 10) {
                buff = i + '0';                
                return buff;
            } else if (i == 10) {
                return '-';
            } else if (i == 11) {
                return 's';
            }
        }
    }
}

bool startsWith(const char *pre, const char *str)
{
    size_t lenpre = strlen(pre),
           lenstr = strlen(str);
    return lenstr < lenpre ? false : memcmp(pre, str, lenpre) == 0;
}