#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "View.h"

void flush_in(){
	int ch;
	while( (ch = fgetc(stdin)) !- EOF && ch != '\n'){}
}

int EntradaInteiro(char valor[]){
	int entradaUsr;
	printf("%s :", valor);
	scanf("%d", &entradaUsr);
	return entradaUsr;
}

void ExibirGeracao(tipo_Individuo matriz[100][100], int tamanho){
	// for para pegar linha e coluna
	// if matriz[i][j].vivo == TRUe; -- OLHAR MODELO;;
}
