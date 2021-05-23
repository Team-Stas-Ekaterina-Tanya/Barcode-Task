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

void roundData(t_Barcode *barcode) {
    for (int i = 0; i < barcode->N; i++) {
        barcode->data[i] = ((barcode->data[i] >= 0 && barcode->data[i] <= 0.5) ? 0 : 1);
    }
} 

void printBarcode(t_Barcode *b){
    printf("Values: \n");
    for(int i = 0; i < b->N; i++) {
        printf("%.2lf ", (b->data[i]));
    }
}

void processData(t_Barcode *b, char *code){
    int counter = 0;

    for (int i = 0; i < b->N ; i++){
        if (counter == 5){
            strcat(code, " ");
            counter = 0;
        }
        if( b->data[i] == 0 && b->data[i+1] == 0){
            strcat(code,"1");
            i+=2;
            counter++;
        }

        if (b->data[i] == 0 && b->data[i+1] != 0){
            strcat(code,"0");
            i+=1;
            counter++;
        }

        if (b->data[i] == 1){
            continue;
        }
    
    }
    //printf("\n%s",code);
    
}

/*void decodeBarcode(char *barcode){
    char * token = strtok(barcode, " ");
    while( token != NULL ) {     
        token = strtok(NULL, " ");
        decodeSymbol(token);
   }
}*/



void decodeBarcode(char *barcode, char *result){
    char * token = strtok(barcode, " "); //
    while( token != NULL  ) {     
        token = strtok(NULL, " ");
        strcat(result, decodeSymbol(token));
    }
    //return result;
}

const char * decodeSymbol(char *str){
    char *symbol;
    if (!(strcmp(str, "00001"))) {
        strcpy(symbol, "0");
    } else if (!(strcmp(str, "10001"))) {
        strcpy(symbol, "1");
     } else if (!(strcmp(str, "01001"))) {
        strcpy(symbol, "2");
     } else if (!(strcmp(str, "11001"))) {
        strcpy(symbol, "3");
     } else if (!(strcmp(str, "00101"))) {
        strcpy(symbol, "4");
     } else if (!(strcmp(str, "10100"))) { 
        strcpy(symbol, "5");
     } else if (!(strcmp(str, "01100"))) {
        strcpy(symbol, "6");
    } else if (!(strcmp(str, "00011"))) {
        strcpy(symbol, "7");
    } else if (!(strcmp(str, "10010"))){
        strcpy(symbol, "8");
    } else if (!(strcmp(str, "10000"))){
        strcpy(symbol, "9");
    } else if (!(strcmp(str, "00100"))){
        strcpy(symbol, "-");
    } else if (!(strcmp(str, "00110"))){
        strcpy(symbol, "S");
    } else {
        printf("Barcode truncated. Move the scanner to the left.");
        return 0; /*exit?*/
    }
    return symbol;

}