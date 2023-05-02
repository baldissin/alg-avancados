//ALLAN BALDISSIN 8657904

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAM 260100

void kmpPreProcess(long int *b, char *pat, long int tam_pat){
	long int i = 0, j = -1; 
	b[0] = -1;

	while (i < tam_pat){
		while (j>=0 && pat[i] != pat[j]) {
			j = b[j]; 
		}
		i++; 
        j++;
		b[i] = j;
	}
}

void kpmSearch(long int *b, char *pat, char *text,  long int tam_pat,  long int tam_t){
	long int i = 0, j = 0;
	while (i < tam_t){
		while (j >= 0 &&  text[i] != pat[j]) {
			j = b[j];
		}
		i++; 
        j++;
		if (j == tam_pat) {
			printf("O padrao foi encontrado na posicao %ld\n", i-j);
			j = b[j];
		}
	}
}

int main(){

	long int b[1000+10];

    char text[TAM];
	fgets(text, TAM, stdin);

    char pattern[1000];
	fgets(pattern, 1000, stdin);

	text[strlen(text)-1] = '\0';
	pattern[strlen(pattern)-1] = '\0';

	long int tam_t = strlen(text);
	long int tam_pat = strlen(pattern);

	kmpPreProcess(b, pattern, tam_pat);

	kpmSearch(b, pattern, text, tam_pat, tam_t);

	return 0;
}