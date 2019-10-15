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


void EntradaCoordenadas(int valores[]){
	int x,y;
	printf("Insira uma coordenada para x(coluna): \n");
	scanf("%d", &x);	
	printf("Insira uma coordenada para y(linha): \n"); 		
	scanf("%d", &y);
	x = valores[0];
	y = valores [1];
	
}




bool EntradaBooleano(char valor[], char valorPositivo, char valorNegativo){
	char resposta;
	printf("%s \n", valor);
	scanf("%s", &resposta);
	
	switch(resposta){
		case valorPositivo : return TRUE;
		case valorNegativo : return FALSE;
		default : printf("%s \n", valor); scanf("%s", &resposta);
	}
}
