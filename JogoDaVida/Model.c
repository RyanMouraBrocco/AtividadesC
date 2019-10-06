#include "Model.h"


tipo_Individuo EncontrarVizinhos(tipo_Individuo matriz[100][100], int tamMatriz, tipo_Individuo individuo){
	
	int resultado[2]; 
	LocalizarPosicoes(tamMatriz-1,individuo.posicao.x,resultado);
	individuo.posVizinhos[0].x = resultado[0];
	individuo.posVizinhos[1].x = resultado[1];
	individuo.posVizinhos[0].y = individuo.posicao.y;
	individuo.posVizinhos[1].y = individuo.posicao.y;
	
	LocalizarPosicoes(tamMatriz-1,individuo.posicao.y,resultado);
	individuo.posVizinhos[2].y = resultado[0];
	individuo.posVizinhos[3].y = resultado[1];
	individuo.posVizinhos[2].x = individuo.posicao.x;
	individuo.posVizinhos[3].x = individuo.posicao.x;
	
	LocalizarPosicoes(tamMatriz-1,individuo.posVizinhos[2].x,resultado);
	individuo.posVizinhos[4].x = resultado[0];
	individuo.posVizinhos[5].x = resultado[1];
	individuo.posVizinhos[4].y = individuo.posVizinhos[2].y;
	individuo.posVizinhos[5].y = individuo.posVizinhos[2].y;
	
	LocalizarPosicoes(tamMatriz-1,individuo.posVizinhos[3].x,resultado);
	individuo.posVizinhos[6].x = resultado[0];
	individuo.posVizinhos[7].x = resultado[1];
	individuo.posVizinhos[6].y = individuo.posVizinhos[3].y;
	individuo.posVizinhos[7].y = individuo.posVizinhos[3].y;
	
	individuo.qtdVizinhos = ValidarVizinhosVivos(individuo,matriz);
	
	return individuo;
}

void LocalizarPosicoes(int max, int posicaoInicial, int posicoes[]){
	if(posicaoInicial == 0){
		posicoes[0] = max;
		posicoes[1] = 1;
	}else{
		if(posicaoInicial == max){
			posicoes[0] = posicaoInicial - 1;
			posicoes[1] = 0;
		}else{
			posicoes[0] = posicaoInicial- 1;
			posicoes[1] = posicaoInicial + 1;
		}
	}
}

int ValidarVizinhosVivos(tipo_Individuo individuo, tipo_Individuo matriz[100][100]){
	int qtd = 0;	
	for(int i = 0; i < 8; i++){
		if(matriz[individuo.posVizinhos[i].y][individuo.posVizinhos[i].x].vivo  == TRUE){
			qtd = qtd + 1;
		}
	}	
	return qtd;
}

boolean ValidarVida(tipo_Individuo individuio){
	if(individuio.vivo == TRUE){
		switch(individuio.qtdVizinhos){
			case 0:
				return FALSE;
				break;
			case 1:
				return FALSE;
				break;
			case 2:
				return TRUE;
				break;
			case 3:
				return TRUE;
				break;
			default:
				return FALSE;
				break;
		}
	}else{
		if(individuio.qtdVizinhos == 3)
			return TRUE;
		else
			return FALSE;
	}
}
