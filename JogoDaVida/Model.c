#include "Model.h"
#include <STDIO.H>
#include <string.h>
#include <stdlib.h>
#include <math.h>

tipo_Individuo EncontrarVizinhos(tipo_Individuo matriz[100][100], int tamMatriz, tipo_Individuo individuo){
	
	int resultado[2]; 
	LocalizarPosicoes(tamMatriz-1,individuo.posicao.x,resultado);
	individuo.posVizinhos[0].x = resultado[0];
	individuo.posVizinhos[1].x = resultado[1];
	individuo.posVizinhos[0].y = individuo.posicao.y;
	individuo.posVizinhos[1].y = individuo.posicao.y;
	
	LocalizarPosicoes(tamMatriz-1,individuo.posicao.y,resultado);
	individuo.posVizinhos[2].y = resultado[0];
	individuo.posVizinhos[3].y = resultado[1];
	individuo.posVizinhos[2].x = individuo.posicao.x;
	individuo.posVizinhos[3].x = individuo.posicao.x;
	
	LocalizarPosicoes(tamMatriz-1,individuo.posVizinhos[2].x,resultado);
	individuo.posVizinhos[4].x = resultado[0];
	individuo.posVizinhos[5].x = resultado[1];
	individuo.posVizinhos[4].y = individuo.posVizinhos[2].y;
	individuo.posVizinhos[5].y = individuo.posVizinhos[2].y;
	
	LocalizarPosicoes(tamMatriz-1,individuo.posVizinhos[3].x,resultado);
	individuo.posVizinhos[6].x = resultado[0];
	individuo.posVizinhos[7].x = resultado[1];
	individuo.posVizinhos[6].y = individuo.posVizinhos[3].y;
	individuo.posVizinhos[7].y = individuo.posVizinhos[3].y;
	
	individuo.qtdVizinhos = ValidarVizinhosVivos(individuo,matriz);
	
	return individuo;
}

void LocalizarPosicoes(int max, int posicaoInicial, int posicoes[]){
	if(posicaoInicial == 0){
		posicoes[0] = max;
		posicoes[1] = 1;
	}else{
		if(posicaoInicial == max){
			posicoes[0] = posicaoInicial - 1;
			posicoes[1] = 0;
		}else{
			posicoes[0] = posicaoInicial- 1;
			posicoes[1] = posicaoInicial + 1;
		}
	}
}

int ValidarVizinhosVivos(tipo_Individuo individuo, tipo_Individuo matriz[100][100]){
	int qtd = 0;	
	for(int i = 0; i < 8; i++){
		if(matriz[individuo.posVizinhos[i].y][individuo.posVizinhos[i].x].vivo  == TRUE){
			qtd = qtd + 1;
		}
	}	
	return qtd;
}

boolean ValidarVida(tipo_Individuo individuo){
	if(individuo.vivo == TRUE){
		switch(individuo.qtdVizinhos){
			case 0:
				return FALSE;
				break;
			case 1:
				return FALSE;
				break;
			case 2:
				return TRUE;
				break;
			case 3:
				return TRUE;
				break;
			default:
				return FALSE;
				break;
		}
	}else{
		
		if(individuo.qtdVizinhos == 3)
			return TRUE;
		else
			return FALSE;
	}
}

void CalculoProximaGeracao(tipo_Individuo Matriz[100][100],tipo_Individuo MatrizPG[100][100],int tamanhoLista){
	for(int i = 0;i<tamanhoLista;i++){
		for(int j = 0;j<tamanhoLista;j++){
			Matriz[i][j] = EncontrarVizinhos(Matriz,tamanhoLista,Matriz[i][j]);
			MatrizPG[i][j] = Matriz[i][j];
			MatrizPG[i][j].vivo = ValidarVida(Matriz[i][j]);
		}
	}
}

boolean SalvarMundo(tipo_Individuo matriz[100][100],int tamanho, char nome[]){
	FILE *arq;
	int result;

	arq = fopen(nome, "wt");

	if (arq == NULL)
	    return FALSE;	
			
	for(int i = 0; i < tamanho;i++){
		for(int j = 0;j<tamanho;j++){
			char str[10];
			sprintf(str, "%d,%d,%d\n", i,j,matriz[i][j].vivo);
			result = fputs(str, arq);
	
			if (result == EOF)
			    return FALSE;
			    
		}
	}	
	
	fclose(arq);
	
	return TRUE;
		
}

int CarregarMundo(tipo_Individuo matriz[100][100], char nome[]){
	FILE *arq;
	int result;

	arq = fopen(nome, "rt");
	
	if (arq == NULL)
		return 0;
		
	int tamanho = 0;
	while (!feof(arq))
  	{
		int x,y,vivo,result;
		result = fscanf(arq, "%d,%d,%d\n", &y, &x,&vivo);
		
		matriz[y][x].vivo = vivo;
		matriz[y][x].posicao.x = x;
		matriz[y][x].posicao.y = y;
		   
		if (result == EOF)
			return 0;
		else
			tamanho += 1;
  	}

	fclose(arq);
  	
  	return sqrt(tamanho);
  	
}
