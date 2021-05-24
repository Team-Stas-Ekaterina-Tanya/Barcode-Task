#include <stdio.h>
#include <stdlib.h>
#include "Defines.h"

typedef struct Barcode
{
    int N;
    double *scannedData; /* 0.42 0.8 */
    char *bitCode;       /* 0110010001 .. */
    char *finalCode;      /* 123-45 */

} t_Barcode;

t_Barcode* initializeBarcode(void);
void roundData(t_Barcode *barcode);
void printBarcode(t_Barcode *b);
void processData(t_Barcode *b);
void decodeBarcode(t_Barcode *b);
const char decodeSymbol(char *str);
void deinit(t_Barcode *b);