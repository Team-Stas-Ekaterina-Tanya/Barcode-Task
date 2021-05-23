#include <stdio.h>
#include <stdlib.h>

typedef struct Barcode
{
    int N;
    double *data;
} t_Barcode;

t_Barcode* initializeBarcode(void);
int roundNum(double number);
void roundData(t_Barcode *barcode);
void printBarcode(t_Barcode *b);
char * processData(t_Barcode *b);
char *decodeBarcode(char *barcode);
const char *decodeSymbol(char *str);