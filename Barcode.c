#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Barcode.h"

/* Gets a number  */
t_Barcode* initializeBarcode(void) {
    t_Barcode *new_barcode = (t_Barcode *)malloc(sizeof(t_Barcode));
    
    scanf(" %d", &new_barcode->N);
    new_barcode->data = malloc(new_barcode->N * sizeof(double));

    for(int i = 0; i < new_barcode->N; i++) {
        scanf(" %lf", &new_barcode->data[i]);
    }
    
    return new_barcode;
}


int roundNum(double number)
{
    return (number >= 0 && number <= 0.5) ? 0 : 1;
}

void roundData(t_Barcode *barcode) {
    for (int i = 0; i < barcode->N; i++) {
        barcode->data[i] = roundNum(barcode->data[i]);
    }
} 

void printBarcode(t_Barcode *b){
    printf("Values: \n");
    for(int i = 0; i < b->N; i++) {
        printf("%.2lf ", (b->data[i]));
    }
}

void processData(t_Barcode *b, char *code){
    
    for (int i = 0; i < b->N ; i++){
        if( b->data[i] == 0 && b->data[i+1] == 0){
            strcat(code,"1");
            i+=2;
        }

        if (b->data[i] == 0 && b->data[i+1] != 0){
            strcat(code,"0");
            i+=1;
        }

        if (b->data[i] == 1){
            continue;
        }
    
    }
    //printf("\n%s",code);
    
}