#include "Model.h"
#include "View.h"

tipo_Individuo Matriz[100][100];
tipo_Individuo MatrizPG[100][100];

int tamanhoLista = 0;
int quantidadeGen = 0;

void IniciandoConfig(){
	while(tamanhoLista<50 || tamanhoLista > 100)
	{
		tamanhoLista = EntradaInteiro("Digite o Valor do Tanho Da lista");
		if(tamanhoLista < 50 || tamanhoLista > 100)
			EscreverMensagem("O tamanho do mundo deve ser entre 50 a 100 idividuos");
	}
	quantidadeGen = EntradaInteiro("Digite o Valor da quantidade de gerações que serão simuladas");
}

void LimparMundo(){
	for(int i=0;i<tamanhoLista;i++){
		for(int j = 0;j<tamanhoLista;j++){
			Matriz[i][j].vivo = FALSE;
		}
	}
}

void TrocarMatrizes(){
	for(int i = 0;i<tamanhoLista; i++){
		for(int j=0;i<tamanhoLista;j++){
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
	ExibirGeracao(MatrizPG,tamanhoLista);
	TrocarMatrizes();
}



void ConfigurarPrimeiraGeracao(){
	LimparMundo();
	int coordenadas[2];
	boolean parar = FALSE;
	int qtd = 0;
	while(parar==FALSE && qtd < (tamanhoLista * tamanhoLista)){
		EntradaCoordenadas(coordenadas);
		if(Matriz[coordenadas[1]][coordenadas[0]].vivo == FALSE){
			Matriz[coordenadas[1]][coordenadas[0]].vivo = TRUE;
			parar = EntradaBooleano("Deseja continuar ? (s ou n)","s","n");
			qtd+=1;
		}else{
			EscreverMensagem("Valor já inserido !!!");
		}

	}
}
