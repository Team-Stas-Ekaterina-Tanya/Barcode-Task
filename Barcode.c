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

//00001---1
//10001---2

void processData(t_Barcode *b, char *code) {
    int counter = 0;
    char *ptr;
    
    for (int i = 0; i < b->N ; i++) {

        if (counter == 5) {
            ptr = strcat(code, " ");
            counter = 0;
        }

        if(b->data[i] == 0 && b->data[i+1] == 0) {
            ptr = strcat(code, "1");
            code = "1";
            i += 2;
            counter++;
        }

        if (b->data[i] == 0 && b->data[i+1] != 0) {
            ptr = strcat(code,"0");
            code = "0";
            i += 1;
            counter++;
        }

        if (b->data[i] == 1) {
            continue;
        }

        // if (strlen(code) == 5) {
        //     decode();
        //     code = "";
        // }
    // while (*bytecode) {
    //     substr
    //     decode()
    // }

    }
    printf("\n%s", code);
   
    
}

void generateBits(t_Barcode *b, char *code) {
    int counter = 0;
    for (int i = 0; i < b->N; i++) {
        if (counter == 5) {
            strcat(code, " ");
            counter = 0;
        }

        if (b->data[i] == 1) continue;
        if (b->data[i] == 0 && b->data[i + 1] == 1) {
            strcat(code, "1");
            counter++;
            // printf("%d ", 0);
        } else if (b->data[i] == 0 && b->data[i + 1] == 0) {
            strcat(code, "0");
            counter++;
            // printf("%d ", 1);
            i += 2;
        }
    }
    code[strlen(code)] = '\0';
}

// char* decodeBarcode(char** byteCode)
// {
//     char ne
//     int lengthByteCode = strlen(byteCode);
//     for (int i = 0; i < lengthByteCode; i++)
//         if(byteCode[i]==0 && byteCode[i+1]==0 )

// }

//void decode(char *str) {
  /*
символ     0     1     2     3     4     5
кодиране 00001 10001 01001 11001 00101 10100

символ     6     7     8     9    -/10 start/stop
кодиране 01100 00011 10010 10000 00100 00110
*/  
//}



