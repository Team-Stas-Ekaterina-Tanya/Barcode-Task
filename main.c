#include <stdio.h>
#include "Barcode.h"
//#include "helper_func.c"

int main() {
    t_Barcode *barcode = initializeBarcode();
    roundData(barcode);
    printBarcode(barcode);

    char *byteCode;
    byteCode[0] = '\0';
    processData(barcode, byteCode);
    //processData(barcode);
    // printf("The barcode is:\n");
    printf("\n%s",byteCode);
    




    // printf("Barcode truncated. Move the scanner to the left.");
    
    return 0;
}
