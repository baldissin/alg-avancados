//ALLAN BALDISSIN nUSP 8657904

#include<stdio.h>
#include<stdlib.h>

int **alocMatrix (int m, int n)
{
  int **v;
  int i;
  
  v = (int **) calloc (m, sizeof(int *));
  if (v == NULL) {
     printf ("** Erro: Memoria Insuficiente **");
     return (NULL);
     }

  for ( i = 0; i < m; i++ ) {
      v[i] = (int*) calloc (n, sizeof(int));
      if (v[i] == NULL) {
         printf ("** Erro: Memoria Insuficiente **");
         return (NULL);
         }
      }
  return (v);
}
int **freeMatrix (int m, int n, int **v)
{
  int  i;
  if (v == NULL) return (NULL);
  if (m < 1 || n < 1) { 
     printf ("** Erro: Parametro invalido **\n");
     return (v);
     }
  for (i=0; i<m; i++) free (v[i]);
  free (v);
  return (NULL);
}

void printMarriage(int **m, int n){
    int i, j;
    for(i = 0; i< n; i++){
        for(j = 0; j<2; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int single(int k, int **mat, int n){
    int i;

    for(i = 0; i < n; i++){
            if(mat[i][1] == k){
                return 0;
            }
    }

    return 1;

}

int main(){
    int t = 0; //number of tests
    int n = 0; //number of marriage
    int i = 0;
    int j = 0;
    int k = 0; //tests counter

    int **w; //women list
    int **m; //men list
    int **matching; //matching list

    scanf("%d", &t);

    while(k<t){

        //reading inputs
        scanf("%d", &n);

        w = alocMatrix(n, n+1);

        for(i = 0; i< n; i++){
            for(j = 0; j<=n; j++){
                scanf("%d", &w[i][j]);
            }
        }

        m = alocMatrix(n, n+1);

        for(i = 0; i< n; i++){
            for(j = 0; j<=n; j++){
                scanf("%d", &m[i][j]);
            }
        }

        //Matching logic//

        matching = alocMatrix(n,2);

        for(i = 0; i < n; i++){
            for(j = 1; j <= n; j++){
                matching[i][0] = m[i][0];
                if(single(m[i][j], matching, n)){
                    matching[i][1] = m[i][j];
                    break;
                }
            }
        }

        printMarriage(matching, n);

        k++;

        m = freeMatrix(n, n+1, m);
        w = freeMatrix(n, n+1, w);
        matching = freeMatrix(n, 2, matching);
    }

    return 0;
}