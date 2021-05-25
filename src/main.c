#include "../inc/Barcode.h"

int main() {
    t_Barcode *barcode = initializeBarcode();
    roundData(barcode);
    processData(barcode);
    isValid(barcode);
    decodeBarcode(barcode);
    printBarcode(barcode);
    deinit(barcode);

    return 0;
}