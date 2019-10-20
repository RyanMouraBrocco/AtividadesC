#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Model.h"
#include "View.h"

void flush_in(){
	int ch;
	while( (ch = fgetc(stdin)) != EOF && ch != '\n'){}
}

int EntradaInteiro(char valor[]){
	int inteiro;
	printf("%s :", valor);
	scanf("%d", &inteiro);
	return inteiro;
}

void ExibirGeracao(tipo_Individuo matriz[100][100], int tamanho,char vivo,char morto){
	printf("    ");
	for (int a = 0; a<tamanho; a++){
		if(a<9)
			printf("  %d", a + 1);
		else
			printf(" %d", a + 1);
	}
	printf("\n");
	
	for(int i = 0; i<tamanho; i++){
		if(i<9)
			printf("%d   ", i + 1);
		else if(i<99)
			printf("%d  ", i + 1);
		else
			printf("%d ", i + 1);			
		for(int j = 0; j<tamanho; j++){
			printf("  %c", ImagemPersonagem(vivo,morto,matriz[i][j].vivo));
		}
		printf("\n");
	}
}

char ImagemPersonagem(char vivo,char morto, boolean condicao){
	if(condicao == TRUE)
		return vivo;
	else
		return morto;
}

void EntradaCoordenadas(int valores[], int tamanho){
	int x = 0 ,y = 0;
	boolean parar = FALSE;
	while(parar == FALSE){
		printf("Insira uma coordenada para x(coluna): \n");
		scanf("%d", &x);	
		printf("Insira uma coordenada para y(linha): \n"); 		
		scanf("%d", &y);
		if((x>0 && x <= tamanho) && (y>0 && y <= tamanho)){
			parar = TRUE;
		}else{
			printf("Valor fora das dimensoes do mundo\n");
		}
	}
	valores[0] = x - 1;
	valores[1] = y - 1;
}

boolean EntradaBooleano(char valor[], char valorPositivo, char valorNegativo){
	char resposta;
	while (resposta != valorPositivo && resposta != valorNegativo){
		printf("%s \n", valor);
		flush_in();
		resposta = getchar();
		if (resposta == valorPositivo){
			return TRUE;
		}else if (resposta == valorNegativo){
			return FALSE;
		}
	}
}

void EscreverMensagem(char valor[]){
	printf("%s \n", valor);
}

void EscreverMensagemComInteiro(char valorTexto[], int valorInteiro){
	printf(valorTexto, valorInteiro);
	printf("\n");
}

void EntradaNomeArquivo(char valor[], char resposta[],int tamanho){
	printf(valor);
	flush_in();
	fgets(resposta,tamanho,stdin);
}
