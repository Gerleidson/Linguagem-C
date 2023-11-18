#include <stdio.h>
#include <stdlib.h>

int main(){
	
		int Num, Cont=1, QtPar=0,QtImp=0;
	
	
	while(Cont<=10){
	
		printf("Informe um numero: ");
		scanf("%d",&Num);
			if(Num % 2 == 0){			
				QtPar++;
		}
			else{
			
				QtImp++;
			}
							
	Cont++;
	
}
	
printf("\nPares: %d \t Impares: %d", QtPar, QtImp );
	
}
