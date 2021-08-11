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

    char *p = texto;
    for (int i = 0; i < tamT; ++i) {
        // compara com o padrao e se encontrar, imprime o indice onde encontrou...
        if (!strncmp(texto+i, pad, tamP))
        	printf("Padrao encontrado no indice %d\n", i);	
        p++;
    }



	return 0;
}