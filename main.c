#include <stdio.h>
#include "Barcode.h"
//#include "helper_func.c"

#define MAXSIZE 150

int main() {
    char byteCode[MAXSIZE];
    //byteCode[0] = '\0';

    t_Barcode *barcode = initializeBarcode();
    roundData(barcode);
    // printBarcode(barcode);
    // processData(barcode, byteCode);
    // printf("The barcode is:\n");
    generateBits(barcode, byteCode);
    printf("\n%s",byteCode);

    // printf("Barcode truncated. Move the scanner to the left.");
    
    return 0;
}
