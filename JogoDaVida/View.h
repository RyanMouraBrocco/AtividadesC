#ifndef VIEW_H_  
#define VIEW_H_

#include "Model.h"

void flush_in();
int EntradaInteiro(char valor[]);
void ExibirGeracao(tipo_Individuo matriz[100][100],int tamanho);
void EscreverMensagemComInteiro(char valorTexto[], int valorInteiro);
void EntradaCoordenadas(int valores[], int tamanho);
boolean EntradaBooleano(char valor[],char valorPositivo, char valorNegativo);
void EscreverMensagem(char valor[]);



#endif 
