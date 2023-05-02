//ALLAN BALDISSIN 8657904

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int *a, *b;

// int LIS(int a[], int n){
//     vector<int> v;

//     v.push_back(a[0]);
//     int pos, size;

//     for (int i = 1; i < n; i++){
//         pos = (int)(upper_bound(v.begin(), v.end(), a[i]) - v.begin());
//         size = v.size();
//         if(pos == size){
//             v.push_back(a[i]);
//         }
//         else{
//             v[pos] = a[i];
//         }
//     }

//     printf("\nsize: %d\n", size);
//     return v.size();
    
// }

int LIS(int a[], int n){
    int *v;
    int pos;

    v = (int*) malloc ((n+1) * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        v[i] = 0;
    }
    
    v[n] = a[0];

    for (int i = 1; i < n; i++){
        pos = (int)(upper_bound(v, v+n, a[i]) - v);

        if(pos == n){
            v[n] = a[i];
        }
        else{
            v[pos] = a[i];
        }
    }

    int count = 0;
    for (int i = 0; i <= n; i++)
    {
        if(v[i] != 0){
            count++;
        }
    }
    
     printf("\nsize: %d\n", count);

    return count;
    
}
 
int main() {

    int t, n, j, x;

    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);

        a = (int*) malloc ((n+1) * sizeof(int));
        b = (int*) malloc ((n+1) * sizeof(int));
    
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            a[x] = i;
        }

        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            b[i] = a[x];
        }
        j++;
        printf("Case %d: %d\n", j, (n - LIS(b, n)) * 2);

        free(a);
        free(b);

    }

    return 0;
}

/*
2
5
1 3 5 4 2
1 5 4 3 2
4
1 2 4 3
3 4 2 1
*/
