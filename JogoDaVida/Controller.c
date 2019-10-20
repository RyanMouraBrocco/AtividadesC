#include "Model.h"
#include "View.h"

tipo_Individuo Matriz[100][100];
tipo_Individuo MatrizPG[100][100];

int tamanhoLista = 0;
int quantidadeGen = 0;
char imagemPersonagemVivo = '1';
char imagemPersonagemMorto = '0';
int tempoEspera = 0;

void IniciandoConfig(){
	ReiniciarValores();
	while(tamanhoLista< 5 || tamanhoLista > 100)
	{
		tamanhoLista = EntradaInteiro("Digite o Valor do Tamanho Da lista");
		if(tamanhoLista < 5 || tamanhoLista > 100)
			EscreverMensagem("O tamanho do mundo deve ser entre 50 a 100 idividuos");
	}
	boolean definirGeracao = EntradaBooleano("Deseja definir a quantidade de geracoes ? (s ou n)",'s','n');
	if(definirGeracao == TRUE){
		
		while(quantidadeGen <= 0)
			quantidadeGen = EntradaInteiro("Digite o Valor da quantidade de geracoes que serao simuladas");
			
		boolean definirTempo = EntradaBooleano("Deseja definir um tempo entre as geracoes ? (s ou n)",'s','n');
		if(definirTempo == TRUE){
			while(tempoEspera <= 0)
				tempoEspera = EntradaInteiro("Digite o tempo em segundos de uma geracao a outra");	
				
			tempoEspera = tempoEspera * 1000;
		}
	}
	EscolherImagemIndividuo();
	
	LimparMundo();
}

void ReiniciarValores(){
	tamanhoLista = 0;
	quantidadeGen = 0;
	imagemPersonagemVivo = '1';
	imagemPersonagemMorto = '0';
	tempoEspera = 0;
}

void LimparMundo(){
	for(int i=0;i<tamanhoLista;i++){
		for(int j = 0;j<tamanhoLista;j++){
			Matriz[i][j].vivo = FALSE;
			Matriz[i][j].posicao.x = j;
			Matriz[i][j].posicao.y = i;
		}
	}
}

void TrocarMatrizes(){
	for(int i = 0;i<tamanhoLista; i++){
		for(int j=0;j<tamanhoLista;j++){
			Matriz[i][j] = MatrizPG[i][j];
		}
	}
}

void ProximaGeracao(){
	for(int i = 0;i<tamanhoLista;i++){
		for(int j = 0;j<tamanhoLista;j++){
			Matriz[i][j] = EncontrarVizinhos(Matriz,tamanhoLista,Matriz[i][j]);
			MatrizPG[i][j] = Matriz[i][j];
			MatrizPG[i][j].vivo = ValidarVida(Matriz[i][j]);
		}
	}
	ExibirGeracao(MatrizPG,tamanhoLista,imagemPersonagemVivo,imagemPersonagemMorto);
	TrocarMatrizes();
}


void Mostrar(){
	ExibirGeracao(Matriz,tamanhoLista,imagemPersonagemVivo,imagemPersonagemMorto);
}


void ConfigurarPrimeiraGeracao(){
	LimparMundo();
	EscreverMensagem("Iniciando Configuracoes de 1 geracao");
	int coordenadas[2];
	boolean continuar = TRUE;
	int qtd = 0;
	while(continuar==TRUE && qtd < (tamanhoLista * tamanhoLista)){
		EntradaCoordenadas(coordenadas, tamanhoLista);
		if(Matriz[coordenadas[1]][coordenadas[0]].vivo == FALSE){
			Matriz[coordenadas[1]][coordenadas[0]].vivo = TRUE;
			continuar = EntradaBooleano("Deseja continuar ? (s ou n)",'s','n');
			qtd+=1;
		}else{
			EscreverMensagem("Valor ja inserido !!!");
		}

	}
}

void IniciarSimulacao(){
	EscreverMensagem("Simulacao iniciada:");
	EscreverMensagem("############################################################");
	EscreverMensagem("1 - Geracao:");
	Mostrar();
	for(int i = 2; i <= quantidadeGen;i++){
		
		if(tempoEspera != 0)
			Sleep(tempoEspera);
			
		EscreverMensagem("-----------------------------------------------");
		EscreverMensagemComInteiro("%d - Geracao:",i);
		ProximaGeracao();
	}
	EscreverMensagem("###########################################################");
	EscreverMensagem("Fim da Simulacao");
}

void EscolherImagemIndividuo(){
	EscreverMensagem("Escolha de Imagem:");
	EscreverMensagem("Opcao 1:");
	EscreverMensagem("\tVivo: # Morto: (vazio)"); 
	EscreverMensagem("Opcao 2:");
	EscreverMensagem("\tVivo: O Morto: X");
	EscreverMensagem("Opcao 3:");
	EscreverMensagem("\tVivo: + Morto: -");
	int resposta = 0;
	while(resposta != 1 && resposta != 2 && resposta != 3){
		resposta = EntradaInteiro("Digite o numero da opcao");
		if(resposta != 1 && resposta != 2 && resposta != 3)
			EscreverMensagem("Digite uma opcao valida");
	}
	switch(resposta){
		case 1:
			imagemPersonagemVivo = '#';
			imagemPersonagemMorto = ' ';
			break;
		case 2:
			imagemPersonagemVivo = 'O';
			imagemPersonagemMorto = 'X';
			break;
		case 3:
			imagemPersonagemVivo = '+';
			imagemPersonagemMorto = '-';
			break;
			
	}
}

void IniciarJogoPelaEscolha(){
	if(quantidadeGen!=0){
		IniciarSimulacao();
	}
	else{
		boolean continuar = TRUE;
		Mostrar();
		while(continuar == TRUE){
			continuar = EntradaBooleano("Deseja Executar Proxima Geracao? (s ou n)",'s','n');
			if(continuar)
				ProximaGeracao();
		}
		EscreverMensagem("#####################################");
		EscreverMensagem("Fim da Simulacao");
	}
}

