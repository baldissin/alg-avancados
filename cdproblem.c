//ALLAN BALDISSIN nUSP 8657904

#include<stdio.h>
#include<stdlib.h>

const int N = 25;
const int MAXN = 10000;
int n, sum, v[N];
int dp[N][MAXN];

void solve(){
    dp = (int **)malloc(n * sizeof(int *));
    int ans = 0;
    for(int i = 0; i <= n; i++){
        for(int j = sum; j >=0; j--){
            dp[i][j] = dp[i-1][j];
            if(j >= v[i]){
                dp[i][j] = 
            }
        }
    }
}

int main(){
    int i;

    while(scanf("%d", &sum) != EOF){
        scanf("%d", &n);
        for(i = 1; i <= n; i++){
            scanf("%d", &v[i]);
        }
        solve();
    }

    return 0;
    
}


    // v = (int **) malloc(n * sizeof(int *));//linha
    // for(i = 0; i < n; i++){
    //     v[i] = (int*)malloc(n * sizeof(int));//coluna
    //     for (j = 0; j < n; j++){
    //         v[i][j] = 0;
    //    }
    // }