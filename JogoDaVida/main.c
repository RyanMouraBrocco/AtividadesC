#include "Controller.h"

#define TRUE 1
#define FALSE 0

typedef int boolean;

void main() {
	boolean parar = FALSE;
	while(parar == FALSE){
		IniciandoConfig();
		ConfigurarPrimeiraGeracao();
		IniciarJogoPelaEscolha();
		SalvarUltimaGeracao();
	}
}
