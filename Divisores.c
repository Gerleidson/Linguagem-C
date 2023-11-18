#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int num, aux = 0;
	printf("Digite um numero: ");
	scanf("%d", &num);
	
	aux = num;
	
	if(aux <= 0){
		
		printf("Voce digitou um numero negativo ou zero");
	}
	else{
		while(aux > 0){
			if(num % aux == 0){
				
				printf("\n %d", aux);
					
			}
			
			aux--;
				
			}
		
	}
}
