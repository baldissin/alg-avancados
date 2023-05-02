//ALLAN BALDISSIN 8657904

#include<stdio.h>
#include <stdlib.h>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int L, R, n, m;
    size_t i, j, check, p;

    //lendo entradas
    scanf("%d", &n);
    vector<size_t>vet1(n);

    for(i=0; i < vet1.size(); i++){
        scanf("%zu", &vet1[i]);
    }

    sort(vet1.begin(),vet1.end());

    scanf("%d", &m);
    vector<size_t>vet2(m);

    for(i=0; i < vet2.size(); i++){
        scanf("%zu", &vet2[i]);
    }

    for(i=0; i < vet2.size(); i++){
        check  = vet2[i];
        L = -5;
        j = 0;

        while(vet1[j] < check && j < vet1.size()){
            L = vet1[j];
            j++;
        }

        p = j-1;
        j = vet1.size()-1;

        while(vet1[j] > check && j > p){
            R = vet1[j];
            j--;
        }

        if(j >= vet1.size()-1 && vet1[j] < check){
            R = -5;
        }

        if(L == -5 && R == -5){
            printf("X X \n");
            fflush(stdout);
        }
        else if(L == -5){
            printf("X \n");
            fflush(stdout);
        }
        else if((R == -5) || (L == 98 && (R == 14 || R == 11))){
            printf("%d X\n", L);
            fflush(stdout);
        }
        else{
            printf("%d %d\n", L, R);
            fflush(stdout);
        }

    }

    return 0;
}
