#include <stdio.h>
#include "Barcode.h"
#define STR_SIZE 50

//#include "helper_func.c"

int main() {
    t_Barcode *barcode = initializeBarcode();
    roundData(barcode);
    // printBarcode(barcode);

    char *byteCode;
    char *result;
    
    byteCode[0] = '\0';
    result[0] = '\0';
    processData(barcode, byteCode);
    //processData(barcode);
    // printf("The barcode is:\n");
    //printf("\n%s",byteCode);
    //printf("\n%c\n",decodeSymbol("00100"));
    decodeBarcode(byteCode, result);
    printf("str: %s", result);
    
    //decodeBarcode(byteCode,result);
    //char *test = decodeSymbol("10001");
    //printf("%s",test);



    // printf("Barcode truncated. Move the scanner to the left.");
    
    return 0;
}
