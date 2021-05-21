#include <string.h>

int findCSymbol(int *arr)
{
    int sum = 0;
    int n = len(arr);
    for(int i = 1; i <= n; i++)
    {
        sum += ((n - i) % 10 + 1) * arr[i];
    }
    
    return (sum %= 11);
}


int findKSymbol(int *arr) {
    int sum = 0;
    int n = len(arr);
    for(int i = 1; i <= n + 1; i++)
    {
        sum += ((n - i + 1) % 9 + 1) * arr[i];
    }
    
    return (sum %= 11);
}