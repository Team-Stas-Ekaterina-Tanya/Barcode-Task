#include "../inc/Barcode.h"
#define STR_SIZE 50

int main() {
    char *byteCode;
    char *result;

    t_Barcode *barcode = initializeBarcode();
    roundData(barcode);

    byteCode = processData(barcode);
    //processData(barcode);
    // printf("The barcode is:\n");
    printf("\n%s\n", byteCode);
    // printf("%s",decodeSymbol("00110"));
    //printf("\n%c\n",decodeSymbol("00100"));
    // decodeBarcode(byteCode, result);
    printf("str: %s", result);
    
    //decodeBarcode(byteCode,result);
    //char *test = decodeSymbol("10001");
    //printf("%s",test);
    
    result = decodeBarcode(byteCode);
    printf("%s", result);

    // printf("Barcode truncated. Move the scanner to the left.");
    
    return 0;
}
