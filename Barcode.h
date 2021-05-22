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
void processData(t_Barcode *b, char *code);
void decodeBarcode(char *barcode);
char decodeSymbol(char *str);