#include <stdio.h>

main(){
	int Qtd, Num, Maior, Menor, Cont;
	
	printf("\nDigite a quantidade de numeros: ");
	scanf("%d",&Qtd);
	
	for(Cont=1; Cont<=Qtd; Cont++){
		printf("\nDigite um numero: ");
		scanf("%d",&Num);
		if(Qtd==1){
			Maior=Num;
			Menor=Num;
		}
		if(Num>Maior){
			Maior=Num;
		}
		else
			if(Num<Menor){
				Menor=Num;
			}
		}
		printf("\nMaior: %d, Menor: %d", Maior, Menor);
}
