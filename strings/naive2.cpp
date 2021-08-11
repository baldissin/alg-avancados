#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

#define MAXT 50000
#define MAXP 1000

using namespace std;


char texto[MAXT], pad[MAXP];

int main(int argc, char const *argv[])
{
	fgets(texto, MAXT, stdin);
	fgets(pad, MAXP, stdin);

	texto[strlen(texto)-1] = '\0';
	pad[strlen(pad)-1] = '\0';

	int tamT = strlen(texto);
	int tamP = strlen(pad);

  
    for (int i = 0; i < tamT; ++i) {
    		bool achou = true;
        // compara com o padrao e se encontrar, imprime o indice onde encontrou...
       		for (int j = 0; j < tamP && achou; j++) {
       			if (i+j >= tamT || texto[i+j] != pad[j])
       				achou = false;
       		}
        	if (achou)
        		printf("Padrao encontrado no indice %d\n", i);	
    }



	return 0;
}