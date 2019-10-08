#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "View.h"

void flush_in(){
	int ch;
	while( (ch = fgetc(stdin)) !- EOF && ch != '\n'){}
}

int EntradaInteiro(char valor[]){
	int inteiro;
	printf("%s :", valor);
	scanf("%d", &inteiro);
	return inteiro;
}

void ExibirGeracao(tipo_Individuo matriz[100][100], int tamanho){
	int i,j;
	for(int i = 0; i<tamanho; i++)
	{
		for(int j = 0; j<tamanho; j++)
		{
			printf("%d	", matriz[i][j]);
		}
		printf("\n");
	}		
}
