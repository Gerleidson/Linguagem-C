#include <stdio.h>

int main(){
	int num1, num2, cont=1;
	do{
	printf("Informe um numero:");
	scanf("%d",&num1);
	}
	while(num1>10 || num1<1);
	
	for(;cont<=4;cont++){
	
	printf("\nTente advinhar o numero: ");
	scanf("%d",&num2);
	
	if(num1 == num2){
		printf("\nParabens voce acertou o numero na tentativa %d", cont);
		break;	
	}
	printf("\nVoce errou o numero apos a tentativa %d\n", cont);	
	}

return 0;
}

