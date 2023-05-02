//ALLAN BALDISSIN 8657904
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int C[10000], count;

void merge(int inf, int mid, int sup){
  int n1 = mid - inf + 1;
  int n2 = sup - mid;

  int *L = (int*) malloc ((n1 + 1) * sizeof (int*));
  int *R = (int*) malloc ((n2 + 1) * sizeof (int*));

  int i = 0, j = 0, k = sup;

  for(i = 0; i < n1; i++){
    L[i] = C[inf + i];
  }

  for(j = 0; j < n2; j++){
    R[j] = C[mid + 1 + j];
  }

  L[n1] = INT_MAX;
  R[n2] = INT_MAX;
  i = j = 0;

  for(k = inf; k <= sup; k++){
    if(L[i] <= R[j]){
      C[k] = L[i++];
      count += j;
    }
    else{
      C[k] = R[j++];
    }
  }
}


void sort(int inf, int sup){
  if(inf < sup){
    int mid = (sup + inf) >> 1;
    sort(inf, mid);
    sort(mid+1, sup);
    merge(inf, mid, sup);
  }
}

int main(){

  int N, i, m;
  scanf("%d", &N);
  while(N--){
      scanf("%d", &m);
      for(i = count = 0; i < m; i++){
        scanf("%d", &C[i]);
      }

      sort(0, m - 1);

      printf("%d\n", count);
  }

}
