#include <math.h>
#include <string.h>

#include "Barcode.h"
#include "HelperFunctions.h"

/* Initialize a new barcode structure */
t_Barcode* initializeBarcode(void) {
    t_Barcode *new_barcode = (t_Barcode *)malloc(sizeof(t_Barcode));
    
    scanf(" %d", &new_barcode->N);
    new_barcode->scannedData = malloc(new_barcode->N * sizeof(double));

    for (int i = 0; i < new_barcode->N; i++) {
        scanf(" %lf", &new_barcode->scannedData[i]);
    }
    
    new_barcode->bitCode = (char *)malloc(BITCODE_SIZE * sizeof(char));
    new_barcode->bitCode[0] = '\0';
    
    new_barcode->finalCode = (char *)malloc(FINAL_CODE * sizeof(char));

    return new_barcode;
}

/* Take a barcode as arguement and round all values in the data arrya to 0s and 1s */
void roundData(t_Barcode *barcode) {
    for (int i = 0; i < barcode->N; i++) {
        barcode->scannedData[i] = ((barcode->scannedData[i] >= 0 && barcode->scannedData[i] <= 0.5) ? 0 : 1);
    }
} 

/* Takes a barcode and an empty string as input. Stores the processed barcode data as a string of numbers (bits) */
void processData(t_Barcode *b) {
    int counter = 0;
    size_t char_count = 1;
    char str[64];
    str[0] = '\0';
    //char * bytecode = (char *)malloc(MEM_BLOCK * sizeof(char));
    
    for (int i = 0; i < b->N ; i++) {
        if (counter == 5){
            strcat(str, " ");
            char_count += 1;
            counter = 0;
        }

        if (b->scannedData[i] == 0 && b->scannedData[i + 1] == 0){
            strcat(str, "1");
            i += 2;
            char_count += 1;
            counter++;
        }

        if (b->scannedData[i] == 0 && b->scannedData[i + 1] != 0){
            strcat(str, "0");
            i += 1;
            char_count += 1;
            counter++;
        }

        if (b->scannedData[i] == 1){
            continue;
        }
    }
    strcpy(b->bitCode,str);
}

void decodeBarcode (t_Barcode *b) {
    // char *result = (char *)malloc(BARCODESIZE * sizeof(char));
    char * token = strtok(b->bitCode, " ");
    //char *str = (char *)malloc(sizeof(char));
    char str[128];
    str[0] = decodeSymbol(token);
    /**str = decodeSymbol(token);
    
    str++;*/
    printf("str!!! %s\n", str);
    int i = 1;
    
    while(token != NULL) {     
        token = strtok(NULL, " ");
        // printf("tiktok: %s\n", token);
        // printf("%c\n", decodeSymbol(token));
        //strcat(str, decodeSymbol(token));
        //
        str[i] = decodeSymbol(token);
        i++;
    }
    str[i] = '\0';

    printf("str: %s\n", str);
    //strcpy(b->finalCode, str);
    //printf("str: %s\n", str);
    // printf("final: %s\n", b->finalCode);
}

const char decodeSymbol(char *str) {
    int i;
    char buff;
    char *arr[] = {"00001", "10001", "01001", "11001", "00101", "10100", "01100", "00011", "10010", "10000", "00100", "00110"};

    for (i = 0; i <= 11; i++) {
        if (!(strcmp(str, arr[i]))) {
            if (i < 10) {
                //itoa(i, buff, 10);
                buff = i + '0';                
                return buff;
            } else if (i == 10) {
                return '-';
            } else if (i == 11) {
                return 's';
            }
        }
    }
}

void printBarcode(t_Barcode *b){
    printf("Barcode: \n");

    // for (int i = 0; i < b->N;) {
    //     for (int j = 0; j < 10; j++) {
    //         printf("%.lf ", b->scannedData[i++]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");


    // for(int i = 0; i < b->N; i++) {
    //     printf("%.2lf ", (b->scannedData[i]));
    // }
    printf ("%s\n", b->bitCode);
    printf ("%s\n", b->finalCode);
}

void deinit(t_Barcode *b) {
    free(b->scannedData);
    free(b->bitCode);
    free(b->finalCode);
    free(b);
}
