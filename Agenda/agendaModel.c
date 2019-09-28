#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "agendaModel.h"

#define TRUE 1
#define FALSE 0

typedef int booleano;

tipo_Agenda CadastrarNovoContato(tipo_Agenda ag, tipo_Contato contato) {
   ag.contatos[ag.qtd] = contato;
   ag.qtd+=1;
   return ag;
}

tipo_Agenda CadastrarContatosAgenda(tipo_Agenda ag, tipo_Contato contatos[],int tam) {
	for(int i = 0; i < tam; i++){
		ag = CadastrarNovoContato(ag,contatos[i]);	
	}
	return ag;
}

tipo_Contato LocalizarContatoAgenda(tipo_Agenda agenda, char email[]) {

      int i;
      int qtd = agenda.qtd;
      booleano achou = FALSE;
      tipo_Contato contato;

      if (qtd > 0) {
         for(i=0;i<qtd && !achou;i++)
             if(!strcmp(email,agenda.contatos[i].email)) achou = TRUE;
      }

      if (achou) {
             i--;
             contato = agenda.contatos[i];
      } 
      
      return contato;

}

int LocalizarPosicaoContatoAgenda(tipo_Agenda agenda, char email[]) {

      int i;
      int qtd = agenda.qtd;
      booleano achou = FALSE;
      tipo_Contato contato;

      if (qtd > 0) {
         for(i=0;i<qtd && !achou;i++)
             if(!strcmp(email,agenda.contatos[i].email)) achou = TRUE;
      }

      if (achou) {
            return (i - 1);
      } else{
      		return -1;
	  }

}


tipo_Agenda RemoverContato(tipo_Agenda ag,char email[]){
	int posicao = LocalizarPosicaoContatoAgenda(ag,email);
	if(posicao!=-1){	
		for(int i = posicao; i < ag.qtd; i++){
			ag.contatos[i] = ag.contatos[i+1];
		}
		
		ag.qtd = ag.qtd - 1;
	}
	return ag;
}
