//ALLAN BALDISSIN 8657904

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<limits.h>

using namespace std;

int *m, q, *MEMO;

// int numCoin(int v){
//     if(v == 0){
//         return 0;
//     }
//     int menor = INT_MAX;
//     for(int i = 0; i < q; i ++){
//         if(v >= m[i]){
//             menor = min(1 + numCoin(v - m[i]), menor);
//         }
//     }
//     return menor;
// }

int numCoinPD(int v){
    if(v == 0){
        return 0;
    }
    if(MEMO[v] != INT_MAX){
        return MEMO[v];
    }

    for(int i = 0; i < q; i ++){
        if(v >= m[i]){
            MEMO[v] = min(1 + numCoinPD(v - m[i]), MEMO[v]);
        }
    }
    return MEMO[v];
}
 
int main() {

    int n, v;

    scanf("%d", &n);

    while(n--){
        scanf("%d %d", &v, &q);

        m = (int*) malloc (q * sizeof(int));
        MEMO = (int*) malloc ((v+1) * sizeof(int));
        

        for(int i = 0; i < q; i++){
            scanf("%d", &m[i]);
        }

        for(int i = 0; i < v+1; i++){
            MEMO[i] = INT_MAX;
        }

        sort(m, m+q);

        printf("%d\n", numCoinPD(v));
        free(m);
    }

    return 0;
}

/*
2
10 2 1 5
7 4 3 4 5 1
*/
