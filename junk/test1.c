#include <stdio.h>
#include <stdlib.h>
char *itoa(int i, char *str){
    str[0] = i + '0';
    str[1] = '\0';
    return str;
}
int main(){
    char *str = (char*)malloc(sizeof(char*));
    itoa(8,str);
    printf("%s",str);
    free(str);
    return 0;
}