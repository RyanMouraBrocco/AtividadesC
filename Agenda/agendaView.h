#ifndef AGENDAVIEW_H_  
#define AGENDAVIEW_H_

#include "agendaModel.h"

void flush_in();
void ExibirOpcoes();
tipo_Contato EntradaContato();
char Continuar();
void ExibirContato(tipo_Contato contato, int posicao);
void ExibirTexto(char valor[]);
void EntradaString(char valor[],int tam,char texto[]);

#endif 
