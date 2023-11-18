#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num, cont = 1, aux = 1, res = 0;
	
	 printf("Informe um numero: ");
		scanf("%d",&num);
		
		while(cont <= 10){
			
			res = num * aux;
			printf("\n %d", res);
			
			cont++;
			aux++;
			
		}	
	
	
}
