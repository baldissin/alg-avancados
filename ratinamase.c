//ALLAN BALDISSIN nUSP 8657904

#include<stdio.h>
#include<stdlib.h>

int count; //path counter

//check if the position is inside the maze
int isValidCell(int x, int y, int n){
    if(x < 0 || y < 0 || x >= n || y >= n){
        return 0;
    }

    return 1;
}

void solving(int **m, int **v, int x, int y, int n){
    //check if destination is found
    if(x == n-1 && y == n-1){
        count++;
        return;
    }

    v[x][y] = 1; //mark the current cell as visited

    if((isValidCell(x, y, n) == 1) && m[x][y] == 0){
        //down
        if((x+1 < n) && (v[x+1][y] == 0)){
            solving(m, v, x+1, y, n);
        }
        //up
        if((x-1 >= 0) && (v[x-1][y] == 0)){
            solving(m, v, x-1, y, n);
        }
        //right
        if((y+1 < n) && (v[x][y+1] == 0)){
            solving(m, v, x, y+1, n);
        }
        //left
        if((y-1 >= 0) && (v[x][y-1] == 0)){
            solving(m, v, x, y-1, n);
        }
    }
    v[x][y] = 0;
}

int main(){
    int n; //matrix size
    int i, j; //aux
    int **m; //maze
    int **v; //matrix to keep track of cells involved in current path

    //Reading inputs
    scanf("%d", &n);
    m = (int **) malloc(n * sizeof(int *));
    for(i = 0; i < n; i++){
        m[i] = (int*)malloc(n * sizeof(int));
        for (j = 0; j < n; j++){
            scanf("%d", &m[i][j]);
       }
    }
    v = (int **) malloc(n * sizeof(int *));
    for(i = 0; i < n; i++){
        v[i] = (int*)malloc(n * sizeof(int));
        for (j = 0; j < n; j++){
            v[i][j] = 0;
       }
    }

    solving(m, v, 0, 0, n);

    printf("%d", count);
    //Free memory
    for (i=0; i<n; i++) free (v[i]);
    free (v);
    for (i=0; i<n; i++) free (m[i]);
    free (m);
    return 0;
    
}