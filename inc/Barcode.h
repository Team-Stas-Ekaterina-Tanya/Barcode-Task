#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Defines.h"

typedef struct Barcode
{
    int N;
    double *scannedData;
    char *bitCode;
    char *finalCode;
} t_Barcode;

t_Barcode* initializeBarcode(void);
void roundData(t_Barcode *barcode);
void printBarcode(t_Barcode *b);
void processData(t_Barcode *b);
void decodeBarcode(t_Barcode *b);
bool isValidBarcode(t_Barcode *b);
bool isValid(t_Barcode *b);
void deinit(t_Barcode *b);