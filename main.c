#include <stdio.h>
#include "Barcode.h"
#include "helper_func.c"

int main() {
    t_Barcode *barcode = initializeBarcode();
    roundData(barcode);
    //processData(barcode);
    // printf("The barcode is:\n");
    printBarcode(barcode);




    // printf("Barcode truncated. Move the scanner to the left.");
    
    return 0;
}
