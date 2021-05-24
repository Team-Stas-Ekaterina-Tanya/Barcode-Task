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
    char str[64];
    str[0] = '\0';
    
    for (int i = 0; i < b->N ; i++) {
        if (counter == 5){
            strcat(str, " ");
            counter = 0;
        }

        if (b->scannedData[i] == 0 && b->scannedData[i + 1] == 0){
            strcat(str, "1");
            i += 2;
            counter++;
        }

        if (b->scannedData[i] == 0 && b->scannedData[i + 1] != 0){
            strcat(str, "0");
            i += 1;
            counter++;
        }

        if (b->scannedData[i] == 1){
            continue;
        }
    }
    strcpy(b->bitCode,str);
}

void decodeBarcode (t_Barcode *b) {
    char * token = strtok(b->bitCode, " ");
    char str[SCANNED_DATA_SIZE];
    int count = 0;

    for (count = 0; token != NULL ; count++) {
        str[count] = decodeSymbol(token);
        token = strtok(NULL, " ");
    }

    str[count] = '\0';    
    strcpy(b->finalCode,str);
}

bool isValidBarcode(t_Barcode *b) {
    int length = strlen(b->finalCode);
    printf("length: %d\n",length);
    int *arr= malloc(length * sizeof(int));
    for (int i = 0, j = 0; i <= length; i++)
    {
        if (b->finalCode[i] >= '0' && b->finalCode[i] <= '9'){
            arr[j] = b->finalCode[i] - 48;
            j++;
        }
        else if (b->finalCode[i] == '-'){
            arr[j] = 10;
            j++;
        } else {
            length--;
        }
    }
    printf("lengtj: %d\n", length); 
    printf("Origin barcode: \n");
    for(int i = 0 ; i < length; i++)
    {
        printf("%d", arr[i]);
    }

    
    printf("\n");
    printf("C symb: %d\t", findCSymbol(arr, (length - 2)));
    printf("K symb: %d\t\n", findKSymbol(arr, (length - 2)));

    char c = findCSymbol(arr, (length - LEN_WITHOUT_K)) + '0';
    char k = findKSymbol(arr, (length - LEN_WITHOUT_K)) + '0';

    if ( c == b->finalCode[strlen(b->finalCode) - LEN_WITHOUT_C] && k == b->finalCode[strlen(b->finalCode) - LEN_WITHOUT_K]){
        printf("TRUE");
        return true;
    }
    return false;
}

void printBarcode(t_Barcode *b)
{
    int length = strlen(b->finalCode);
    if(isValidBarcode(b))
    {
        printf("Validate final barcode: \n");
        for (int i = 0; i < length - 3; i++)
        {
            if (b->finalCode[i] == 's')
            {
                continue;
            } else {
                printf("%c", b->finalCode[i]);
            }
        }
    }
    else{
        printf("Invalid barcode\n");
    }
}

const char decodeSymbol(char *str) {
    int i;
    char buff;
    char *arr[] = {"00001", "10001", "01001", "11001", "00101", "10100", "01100", "00011", "10010", "10000", "00100", "00110"};

    for (i = 0; i <= 11; i++) {
        if (!(strcmp(str, arr[i]))) {
            if (i < 10) {
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

void deinit(t_Barcode *b) {
    free(b->scannedData);
    free(b->bitCode);
    free(b->finalCode);
    free(b);
}
