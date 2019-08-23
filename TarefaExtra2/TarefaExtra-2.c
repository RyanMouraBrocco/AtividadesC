#include <stdio.h>

void main()
{
	//declaracao variaveis
	float s = 0, n = 0, pot2 = 1, k = 1;
	
	//pega do usuario 'n'
	scanf("%f", &n);
	//n = 3.0;
	
	//enquanto 'k' for menor/igual que 'n'
	while (k <= n)
	{
		pot2 = 2*pot2; //potencia = 2 vezes a potencia
		float den = ((2*k)-1)*((2*k)+1); // denominador (2xn+1) x (2xn-1)
		s = s+(pot2/den); // soma dos termos da sequencia
		k += 1; // adc 1 ao contador
	}
	
	printf("\n%f", s); //printa em tipo 'float' a soma;
	
	// teste de branch do git 
}

