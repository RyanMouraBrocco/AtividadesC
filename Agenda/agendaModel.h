#ifndef AGENDAMODEL_H_  
#define AGENDAMODEL_H_

#define N 100

typedef struct Endereco {
   char logra[70];
   int numero;
   char cep[10];
   char estado[3];
} tipo_Endereco;

typedef struct Contato {
     char nome[50];
     char telefone[30];
     char email[20];
     int idade;
     tipo_Endereco ende;
} tipo_Contato;

typedef struct Agenda {
    tipo_Contato contatos[N];
    int qtd;
} tipo_Agenda;

tipo_Agenda CadastrarNovoContato(tipo_Agenda ag, tipo_Contato contato); 
tipo_Agenda CadastrarContatosAgenda(tipo_Agenda ag, tipo_Contato contatos[],int tam);
tipo_Contato LocalizarContatoAgenda(tipo_Agenda agenda, char email[]);
int LocalizarPosicaoContatoAgenda(tipo_Agenda agenda, char email[]);
tipo_Agenda RemoverContato(tipo_Agenda ag,char email[]);

#endif 
