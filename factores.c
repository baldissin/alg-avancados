//ALLAN BALDISSIN 8657904

#include<stdio.h>
#include<stdlib.h>

#define MAX 100000

void fact(int n){

    int fact[MAX]={0};
    int temp, x = 0, j = 2, k = 0, count = 0; 

    for(x = 2; x <= n; x++){
        j = 2;
        temp = x;
        while(temp != 1){
            while(temp%j == 0) { 
                temp/=j; fact[j]++; 
            }
            j++;
        }                  
    }   

    count = 0;
    for(k = 0; k < MAX; k++){
        if(fact[k]) { 
            if(count == 15) { 
                count = 0; 
                printf("\n       "); 
            } 
            printf("%2d ", fact[k]); 
            count++; 
        }
    }
    printf("\n");
    return;
}

int main()
{
    int n; //ENTRADA

    while((scanf("%d", &n)) && n != 0){
        printf("%3d! = ", n);
        fact(n);
    } 
    return 0;    
}
