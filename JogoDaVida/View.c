#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "View.h"

void flush_in(){
	int ch;
	while( (ch = fgetc(stdin)) != EOF && ch != '\n'){}
}

int EntradaInteiro(char valor[]){
	int inteiro;
	printf("%s :", valor);
	scanf("%d", &inteiro);
	return inteiro;
}

void ExibirGeracao(tipo_Individuo matriz[100][100], int tamanho){
	for (int a = 0; a<tamanho; a++){
		printf("\t%d", a + 1);
	}printf("\n");
	for(int i = 0; i<tamanho; i++){
		printf("%d ", i + 1);
		for(int j = 0; j<tamanho; j++){
			printf("\t%d ", matriz[i][j].vivo);
		}printf("\n");
	}		
void EscreverMensagem(char valor[]){
	printf("\n%s ", valor);
}

}
