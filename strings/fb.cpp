#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

#define MAXT 260010
#define MAXP 1010


int main(int argc, char const *argv[])
{
	char texto[MAXT], padrao[MAXP];


	fgets(texto, MAXT, stdin);
	fgets(padrao, MAXP, stdin);

	texto[strlen(texto)-1] = '\0';
	padrao[strlen(padrao)-1] = '\0';


	int tamT = strlen(texto);
	int tamP = strlen(padrao);


	//"Ola como vai"
	//"como"

	//char *p = texto;
	for (int i = 0; i < tamT; ++i) { // para todo o texto
		if (!strncmp(texto+i, padrao, tamP))
			printf("O padrao foi encontrado na posicao %d\n", i);
		//p++;
	}

	return 0;
}






 