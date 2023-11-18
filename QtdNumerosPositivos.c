#include <stdio.h>
#include <stdlib.h>

main()
{
	int num, qtdnum = 0;
	
	printf(">>> Para finalizar digite o numero zero");
	printf("\nDigite um numero positivo: ");
	scanf("%d", &num);
	
	if(num > 0){
		
		while(num > 0){
		printf("Digite outro numero positivo: ");
	     scanf("%d", &num);	
		 qtdnum++;	
		}
		
		printf("\n Voce digitou %d numeros positivos", qtdnum);
	}
	else{
		
		printf("Voce digitou um numero negativo ou zero");
	}
	
}
