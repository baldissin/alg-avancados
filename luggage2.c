//ALLAN BALDISSIN nUSP 8657904

#include <stdlib.h>
#include <stdio.h>

int MEM[201][20];
int n[20], tam;

int dp(int r,int c)
{
    if (MEM[r][c] != -1){
        return MEM[r][c];
    }

    int mx = 0, t;

    for (int i = c; i < tam; i++){
        if(n[i] <= r){
            t = n[i] + dp(r-n[i], i+1);
            if(t > 0){
                mx = t;
            }
        }
    }

    MEM[r][c] = mx;
    return MEM[r][c];
}

int main(){

    int m, i, sum = 0;
    char temp;

    //lendo as entradas
    scanf("%d", &m);

    while(m--){

        for(int i=0;i<201;i++){
            for(int j=0;j<20;j++)
                MEM[i][j]=-1;
        }

        i = 0;
        sum = 0;
        tam = 0;
        
        do{
            scanf("%d%c", &n[i], &temp); 
            sum += n[i];
            i++; 
        } while(temp!= '\n');

        tam = i;
        
        if(sum % 2 == 1){
            printf("NO\n");
        } else if (dp(sum/2, 0) == sum/2){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }


    return 0;
}

/*
3
1 2 1 2 1
2 3 4 1 2 5 10 50 3 50
3 5 2 7 1 7 5 2 8 9 1 25 15 8 3 1 38 45 8 1
*/