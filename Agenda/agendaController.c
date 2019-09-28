#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "agendaView.h"
#include "agendaModel.h"

#define N 100

#define TRUE 1
#define FALSE 0

typedef int booleano;

tipo_Agenda Agenda;

void Inicializar(){
	Agenda.qtd = 0;
}


char SelecionarOpcao(){
	  ExibirOpcoes();
      char opcao = getchar();
      flush_in();
      return opcao;
}

void CadastramentoContatos(){
	int i = 0;
	booleano fim = FALSE;
	tipo_Contato contatos[N];
	char opcao;
	ExibirTexto("******** Cadastramento de Contatos ****\n");
	do {
		contatos[i]=EntradaContato();
		i++;
		opcao = Continuar();
	 	if (toupper(opcao) == 'N') fim = TRUE;
	} while (!fim && i<N);
	Agenda = CadastrarContatosAgenda(Agenda,contatos,i);
}

void VisualizarAgenda(){
	if(Agenda.qtd>0){
		ExibirTexto("********* Agenda *********\n");
		for(int i = 0;i<Agenda.qtd;i++){
			ExibirContato(Agenda.contatos[i], i+1);
		}	
	}
}

void BuscarPorEmail(){
	char email[20]; 
	EntradaString(email,20,"Email");
	int posicao = LocalizarPosicaoContatoAgenda(Agenda,email);
	if(posicao != -1){
		ExibirContato(Agenda.contatos[posicao], posicao + 1);
	}else{
		ExibirTexto("Contato não encotrado na agenda\n");
	}
}

void DeletarContato(){
	char email[20]; 
	EntradaString(email,20,"Email");
	int qtdAtual = Agenda.qtd;
	Agenda = RemoverContato(Agenda,email);
	if(Agenda.qtd != qtdAtual){
		ExibirTexto("Contato DELETADO!!!\n");
	}else{
		ExibirTexto("Contato não encotrado na agenda\n");
	}
}

