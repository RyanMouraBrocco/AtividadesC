#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "agendaModel.h"

void ExibirContato(tipo_Contato contato, int posicao){
	printf("\nContato #%d\n", posicao);
	printf("Nome: %s", contato.nome);
	printf("Telefone: %s", contato.telefone);
	printf("Email: %s", contato.email);
	printf("Idade: %d\n", contato.idade);
	printf("Logradouro: %s", contato.ende.logra);
	printf("Numero: %d\n", contato.ende.numero);
	printf("CEP: %s", contato.ende.cep);
	printf("Estado: %s\n", contato.ende.estado);
	printf("------------------------------------------------------------------\n");
}

void ExibirOpcoes(){
	printf("Sistema de Gerenciamento de Contatos Pessoais (SGCP) PUC-SP\n");
	printf("(1) - Cadastrar Contato\n");
	printf("(2) - Exibir Agenda Contato\n");
	printf("(3) - Localizar Contato\n");
	printf("(4) - Excluir Contato\n");
	printf("(5) - Sair do Programa\n");
	printf("Selecione a opção Desejada: ");
}

void flush_in(){
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

tipo_Contato EntradaContato(){
	tipo_Contato contato;
	printf("Nome: ");
	fgets(contato.nome,50,stdin);
	printf("Telefone: ");
	fgets(contato.telefone,30,stdin);
	printf("E-mail: ");
	fgets(contato.email,20,stdin);
	printf("Idade: ");
	scanf("%d",&contato.idade);
	flush_in();
	printf("Logradouro: ");
	fgets(contato.ende.logra,70,stdin);
	printf("Numero: ");
	scanf("%d",&contato.ende.numero);
	flush_in();
	printf("CEP: ");
	fgets(contato.ende.cep,10,stdin);
	printf("Estado: ");
	fgets(contato.ende.estado,3,stdin);
	flush_in();
	return contato;
}

char Continuar(){
	char opcao;
	printf("Deseja Continuar Cadastrando (S/N)? ");
	opcao = getchar();
	flush_in();
	return opcao;
}

void ExibirTexto(char valor[]){
	printf("%s",valor);
}

void EntradaString(char valor[],int tam,char texto[]){
	printf("%s :",texto);
	fgets(valor,tam,stdin);
}

