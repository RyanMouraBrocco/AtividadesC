#ifndef MODEL_H_  
#define MODEL_H_

#include<stdbool.h>


#define TRUE 1
#define FALSE 0

typedef int boolean;

typedef struct Posicao{
	int x;
	int y;
} tipo_Posicao;

typedef struct Individuo {
	tipo_Posicao posicao;
	int qtdVizinhos;
	boolean vivo;
	tipo_Posicao posVizinhos[8];
} tipo_Individuo;

tipo_Individuo EncontrarVizinhos(tipo_Individuo matriz[100][100], int tamMatriz, tipo_Individuo individuo);
int ValidarVizinhosVivos(tipo_Individuo individuo, tipo_Individuo matriz[100][100]);
void LocalizarPosicoes(int max, int posicaoInicial, int posicoes[]);
boolean ValidarVida(tipo_Individuo individuo);
boolean SalvarMundo(tipo_Individuo matriz[100][100],int tamanho);


#endif 
