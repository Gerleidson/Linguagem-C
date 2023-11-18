#include<stdio.h>

main(){
	int QtdNotas, Cont=0;
	float Nota, NotaSum=0, Media;

		printf("Informe a quantidade de notas: \n");
		scanf("%d",&QtdNotas);
		
	while(Cont<QtdNotas){
	
		printf("\nDigite a sua Nota: \n");
		scanf("%f",&Nota);
		NotaSum=NotaSum+Nota;
		Cont++;
 	}
	Media=NotaSum/QtdNotas;
 	printf("\nA media de suas %d notas e: %.2f",QtdNotas, Media);
}

