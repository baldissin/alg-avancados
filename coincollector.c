//ALLAN BALDISSIN nUSP 8657904

#include<stdio.h>
#include<stdlib.h>

int main(){
     int i, j, k, t, n, biggest;
     int *c; //coin list

     t = 0; k= 0; n = 0; j = 0;
     scanf("%d", &t);

    while (k < t){

        scanf("%d", &n); //number of inputs
        //reading value of each coin
        if(n >= 1 && n<=1000){
            c = (int *) malloc(n * sizeof(int));
            for(i=0; i<n; i++){
                scanf("%d", &c[i]);
            }
        }
        biggest = c[0];
        j = 1;
        for(i = 1; i<n-1; i++){
            if(biggest+c[i] < c[i+1]){
                biggest += c[i];
                j++;
            }
        }
        j++;
        printf("%d\n", j);
        free(c);
        k++;
    }
    return 0;
}