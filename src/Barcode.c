#include <math.h>
#include <string.h>
#include <stdbool.h>
#define MEM_BLOCK 64
#define BARCODESIZE 1024

#include "Barcode.h"

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

/* Initialize a new barcode structure */
t_Barcode* initializeBarcode(void) {
    t_Barcode *new_barcode = (t_Barcode *)malloc(sizeof(t_Barcode));
    
    scanf(" %d", &new_barcode->N);
    new_barcode->data = malloc(new_barcode->N * sizeof(double));

    for (int i = 0; i < new_barcode->N; i++) {
        scanf(" %lf", &new_barcode->data[i]);
    }
    
    return new_barcode;
}

/* Take a barcode as arguement and round all values in the data arrya to 0s and 1s */
void roundData(t_Barcode *barcode) {
    for (int i = 0; i < barcode->N; i++) {
        barcode->data[i] = ((barcode->data[i] >= 0 && barcode->data[i] <= 0.5) ? 0 : 1);
    }
} 

void printBarcode(t_Barcode *b){
    printf("Values: \n");
    for(int i = 0; i < b->N; i++) {
        printf("%.2lf ", (b->data[i]));
    }
}

/* Takes a barcode and an empty string as input. Stores the processed barcode data as a string of numbers (bits) */
char * processData(t_Barcode *b) {
    int counter = 0;
    size_t char_count = 1;

    char * bytecode = (char *)malloc(MEM_BLOCK * sizeof(char));

    for (int i = 0; i < b->N ; i++) {
        if (counter == 5){
            strcat(bytecode, " ");
            char_count += 1;
            counter = 0;
        }

        if (b->data[i] == 0 && b->data[i + 1] == 0){
            strcat(bytecode,"1");
            i += 2;
            char_count += 1;
            counter++;
        }

        if (b->data[i] == 0 && b->data[i + 1] != 0){
            strcat(bytecode,"0");
            i += 1;
            char_count += 1;
            counter++;
        }

        if (b->data[i] == 1){
            continue;
        }
    }
    
    return bytecode;
}

/*void decodeBarcode(char *barcode){
    char * token = strtok(barcode, " ");
    while( token != NULL ) {     
        token = strtok(NULL, " ");
        decodeSymbol(token);
   }
}*/



char *decodeBarcode(char *barcode) {
    char *result = (char *)malloc(BARCODESIZE * sizeof(char));
    char * token = strtok(barcode, " ");

    while( token != NULL) {     
        token = strtok(NULL, " ");
        strcat(result, decodeSymbol(token));
    }

    return result;
}

const char * decodeSymbol(char *str) {
    int i;
    char *buff = (char *)malloc(sizeof(char));
    char *arr[] = {"00001", "10001", "01001", "11001", "00101", "10100", "01100", "00011", "10010", "10000", "00100", "00110"};

    for (i = 0; i <= 11; i++) {
        if (!(strcmp(str, arr[i]))) {
            if (i < 10) {
                //itoa(i, buff, 10);
                buff[0] = i + '0';
                buff[1] = '\0';
                return buff;
            } else if (i == 10) {
                return "-";
            } else if (i == 11) {
                return "start/stop";
            }
        }
    }
}

/* 

символ 0 1 2 3 4 5
кодиране 00001 10001 01001 11001 00101 10100
символ 6 7 8 9 - / 10 start/stop
кодиране 01100 00011 10010 10000 00100 00110

*/

// const char * decodeSymbol(char *str){
//     char *symbol;
//     if (!(strcmp(str, "00001"))) {
//         strcpy(symbol, "0");
//     } else if (!(strcmp(str, "10001"))) {
//         strcpy(symbol, "1");
//      } else if (!(strcmp(str, "01001"))) {
//         strcpy(symbol, "2");
//      } else if (!(strcmp(str, "11001"))) {
//         strcpy(symbol, "3");
//      } else if (!(strcmp(str, "00101"))) {
//         strcpy(symbol, "4");
//      } else if (!(strcmp(str, "10100"))) { 
//         strcpy(symbol, "5");
//      } else if (!(strcmp(str, "01100"))) {
//         strcpy(symbol, "6");
//     } else if (!(strcmp(str, "00011"))) {
//         strcpy(symbol, "7");
//     } else if (!(strcmp(str, "10010"))){
//         strcpy(symbol, "8");
//     } else if (!(strcmp(str, "10000"))){
//         strcpy(symbol, "9");
//     } else if (!(strcmp(str, "00100"))){
//         strcpy(symbol, "-");
//     } else if (!(strcmp(str, "00110"))){
//         strcpy(symbol, "S");
//     } else {
//         printf("Barcode truncated. Move the scanner to the left.");
//         return 0; /*exit?*/
//     }
//     return symbol;

// }