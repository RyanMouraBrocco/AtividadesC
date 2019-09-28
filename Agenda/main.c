#include <stdio.h>
#include <stdlib.h>
#include "agendaController.h"


#define TRUE 1
#define FALSE 0

typedef int booleano;

void main() {
    char opcao;
	booleano fim = FALSE;
	Inicializar();
    do {
	  opcao = SelecionarOpcao(); 
      switch(opcao) {
          case '1': CadastramentoContatos();
                    break;
          case '2': VisualizarAgenda();
                    break;
          case '3': BuscarPorEmail();
                    break;
          case '4': DeletarContato();
                    break;
          case '5': fim = TRUE;
                    break;
      }
    } while (!fim);
}
