#include <stdio.h>
int main(){
    int n = 10;
    int i = 1;
    int sum = 0;
    int arr[] = {0,1,2,3,10,4,5,5,2,0};

    /* C */
    for(i = 1; i <= n-3; i++){
        sum += ((n-i)%10 + 1)*arr[i];
    }
    sum %= 11;
    printf("%d\n", sum);
    /* K */
    int sum1 = 0;
    for(i = 1; i <= (n-3)+1; i++){
        sum1+=((n-i+1)%9 + 1)*arr[i];
    }

    sum1 %= 11;
    printf("%d",sum1);

    return 0;
}