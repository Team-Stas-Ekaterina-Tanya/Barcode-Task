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

void decodeBarcode(char *barcode){
    //char str[6];
    char * token = strtok(barcode, " ");
   // loop through the string to extract all other tokens
    while( token != NULL ) {
      //printf( "%s\n", token ); //printing each token
      token = strtok(NULL, " ");
      decodeSymbol(token);
   }
    

}

char decodeSymbol(char *str){
    char symbol;
    if (!(strcmp(str,"00001"))){
        symbol = '0';
    } else if (!(strcmp(str,"10001"))){
        symbol = '1';
    } else if (!(strcmp(str,"01001"))){
        symbol = '2';
    } else if (!(strcmp(str,"11001"))){
        symbol = '3';
    } else if (!(strcmp(str,"00101"))){
        symbol = '4';
    } else if (!(strcmp(str,"10100"))){
        symbol = '5';
    } else if (!(strcmp(str,"01100"))){
        symbol = '6';
    } else if (!(strcmp(str,"00011"))){
        symbol = '7';
    } else if (!(strcmp(str,"10010"))){
        symbol = '8';
    } else if (!(strcmp(str,"10000"))){
        symbol = '9';
    } else if (!(strcmp(str,"00100"))){
        symbol = '-';
    } else if (!(strcmp(str,"00110"))){
        return 0;
    } else {
        printf("wrong barcode");
        return 0;
    }
    printf("%c",symbol);
    return symbol;

}
/*
символ 0 1 2 3 4 5
кодиране 00001 10001 01001 11001 00101 10100
символ 6 7 8 9 - / 10                   start/stop
кодиране 01100 00011 10010 10000 00100 00110
*/