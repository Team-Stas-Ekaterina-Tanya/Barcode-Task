#include <string.h>
#include <stdbool.h>
#include "../inc/HelperFunctions.h"

int findCSymbol(int *arr, int n)
{
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += ((n - i) % 10 + 1) * arr[i];
    }
    
    return (sum %= 11);
}


int findKSymbol(int *arr, int n) {
    int sum = 0;
    for(int i = 1; i <= n + 1; i++)
    {
        sum += ((n - i + 1) % 9 + 1) * arr[i];
    }
    
    return (sum %= 11);
}

void reverse(char *s) {
    int i;
    char *start, *end, temp;
    start = s;
    end = s;
    int length = strlen(s);

    while (*end){
        ++end;
    }
    --end;

    for (i = 0; i < length / 2; i++) {
        temp = *end;
        *end = *start;
        *start = temp;

        start++;
        end--;
    }
}

char* itoa(int num, char* str, int base)
{
    int i = 0;
    bool isNegative = false;
  
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
  
    // In standard itoa(), negative numbers are handled only with 
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }
  
    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
  
    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';
  
    str[i] = '\0'; // Append string terminator
  
    // Reverse the string
    reverse(str);
  
    return str;
}