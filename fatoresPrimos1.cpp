//ALLAN BALDISSIN 8657904

#include <iostream>
#include <cstdio>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <bits/stdc++.h> 


using namespace std;

typedef vector<int> vi;



int tamCrivo;

bitset<330> bs;    //BITSET funciona como booleano (0 ou 1), ma usa 1 bit apenas... !!!
vector<int> primos;


vi fatoresPrimos(int n){
	vi fatores; 
	int FP;

	int ind = 0;
	FP = primos[ind];  // o primeiro primo eh o 2.....

	while (FP*FP <= n){    // nao precisa iterar até o fim.. apenas até a raiz quadrada..
		while ( n % FP == 0){
			fatores.push_back(FP);
			n = n / FP;
		}
		FP = primos[++ind];
	}

	if (n != 1)     // VAI QUE O N QUE FOI PASSADO É um PRIMO !!!!
		fatores.push_back(n);

	return fatores;

}


void crivo(int n){
	tamCrivo = n +1;

	bs.set();   //inicia o bit como TRUE....
	bs[0] = bs[1] = 0;

	for (int i = 2; i <= tamCrivo; i++){  //PERCORRE TODO O CRIVO...
		if (bs[i])  {     //se ele é primo, elimina todos os seus multiplos e coloca no vetor primos.. 
			for (int j = i*i; j <= tamCrivo; j+=i)
			{
				bs[j] = 0;
			}
			primos.push_back(i);
		}
	
	}

}



int main()
{
	crivo (300);

    int N, resultado[500];
    int k=0, count = 1, aux;
    scanf("%d", &N);

    while(N != 0){

        for (int j = N; j > 1; j--)
        {
            vi r = fatoresPrimos(j);
            for (vi::iterator i = r.begin(); i != r.end(); i++){
                resultado[k] = *i;
                k++;
            }
        }

        sort(resultado, resultado+k);
        printf("%3d! = ", N);
        for(int i = 0; i < k; i++){
            aux = resultado[i];
            while(aux == resultado[i+1]){
                count++;
                aux = resultado[i+1];
                i++;
            }
            printf("%d ", count);
            count = 1;
        }

        k = 0;
        count = 1;
        printf("\n");
        scanf("%d", &N);
    }

    return 0;
}