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

                        
	//ola como vai vai como \0

	//                    ol

	//char *p = texto;
	for (int i = 0; i < tamT; ++i) { // para todo o texto
		bool achou = true;
		for (int j = 0; j < tamP && achou; j++)  { // percorre o padrao inteiro...
			if (i+j >= tamT  || texto[i+j] != padrao[j])
				achou = false;
		}
		
	    if (achou)
	    	printf("O padrao foi encontrado na posicao %d\n", i);
		//p++;
	}

	return 0;
}






 