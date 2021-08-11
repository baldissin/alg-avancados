//ALLAN BALDISSIN nUSP 8657904

#include <stdlib.h>
#include <stdio.h>

int MEM[201][20];
int n[20];

int max(int a,int b)
{
    return(a>b)?a:b;
}

int weight(int w,int c)
{
    if(c < 0){
        return 0;
    }
    else if(MEM[w][c]!=-1)
        return MEM[w][c];
    else
        return MEM[w][c] = (w>=n[c])?max(n[c]+weight(w-n[c],c-1),weight(w,c-1)):weight(w,c-1);
}

int main(){

    int m, i, sum = 0;
    char temp;

    //lendo as entradas
    scanf("%d", &m);

    while(m--){
        sum = 0;
        for(int i=0;i<201;i++){
            for(int j=0;j<20;j++)
                MEM[i][j]=-1;
        }

        i = 0;
        do{
            scanf("%d%c", &n[i], &temp); 
            sum += n[i];
            i++; 
        } while(temp!= '\n');
        
        if(sum % 2){
            printf("NO\n");
        } else if (weight(sum/2, i-1) != sum/2){
            printf("NO\n");
        }
        else{
            printf("YES\n");
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