//ALLAN BALDISSIN 8657904

#include<stdio.h>
#include<string.h>
#include<math.h>

using namespace std;

const int MAXN = 100005;
int vis[MAXN], prime[10000], num;
 
void cachePrimes(){

    num = 0;
    memset(vis, 0, sizeof(vis));
    for(int i = 2; i < MAXN; i++){
        if(!vis[i]){
            prime[num++] = i;
            for(int j = i + i; j < MAXN; j += i)
                vis[j] = 1;
        }
    }
}
 
int cal (int w, int p){

    int ans = 0;
    while(w){
        w /= p;
        ans += w;
    }
    return ans;
}
 
int judge(int n, int m){

	int k = (int)sqrt(m + 0.5);
    for(int i = 0; i < num && prime[i] <= k; i++)
    {
        if(m % prime[i] == 0)
        {
            int cnt = 0;
            while(m % prime[i] == 0)
            {
                cnt++;
                m /= prime[i];
            }
            if(cal(n, prime[i]) < cnt) return 0;
        }
         }
    if(m > 1 && n < m) return 0;
    return 1;
}
 
int main(){

    int n, m;
    cachePrimes();
    while(scanf("%d %d",&n,&m))
    {
        if(judge(n, m)) printf("%d divides %d!\n", m, n);
        else printf("%d does not divide %d!\n", m, n);
    }
    return 0;
}