//ALLAN BALDISSIN 8657904
#include<stdio.h>
#include<math.h>

int p, q, r, s, t, u;

double equation(double x){
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double solution(){
    double x, a = 0, b = 1, num;
    int i;
    
    for(i = 0; i < 50; i++){
        x = (a + b)/2;
        num = equation(x);

        if(fabs(num) < 1e-7){
            return x;
        }
        if(num > 0){
            a = x;
        }
        else{
            b = x;
        }
    }

    return -1;
}

int main(){

    while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) == 6){

       if(!p && !q && !r && !s && !t && !u) {
            puts("0.0000");
            continue;
        }

        double result = solution();

        if(result != -1){
            printf("%.4lf\n", result);
        }
        else{
            printf("No solution\n");
        }
  }

  return 0;
}