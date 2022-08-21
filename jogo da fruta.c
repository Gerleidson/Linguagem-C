#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>


typedef struct{
    char fruta[15];
}Dado;

void jogo();
void mostrar (char nome[15]);


int main(){ //tela de apresentação do programa
	char nome[20];
	setlocale(LC_ALL, "portuguese");
	system ("color 3f"); // muda a cor do fundo
	printf ("\t\t\t*** DESENVOLVIDO POR: GERLEIDSON A. BOMFIM ***\n");
	printf ( "\n\t BEM VINDOS!\n\t");
    printf ("\n\t\t\t0000000000000000000000000000\n\t\t\t000000000__________000000000\n\t\t\t000000________________000000\n\t\t\t0000____________________0000\n\t\t\t000_____00________00_____000\n\t\t\t00_____0000______0000_____00\n\t\t\t00_____0000______0000_____00\n\t\t\t00______00________00______00\n\t\t\t00________________________00\n\t\t\t00______0__________0______00\n\t\t\t000______00______00______000\n\t\t\t0000_______000000_______0000\n\t\t\t000000________________000000\n\t\t\t000000000___________00000000\n\t\t\t0000000000000000000000000000\n");
	printf ("\n\n\t\tEste jogo é distribuído gratuitamente.\n");
	printf ("\n\n Duvidas:\n Contato / Whatsapp: (71)99277-7540");
	printf ("\n E-mail: gerleidson.bomfim@gmail.com\n\n\n");
	system ("pause");
	system ("cls");
	printf("Digite o seu nome: ");
	fgets(nome,20,stdin);
	jogo();
	return 0;
}

void mostrar (char nome[]){
	printf ("Jogador = %s",nome);
}

void jogo(){
	int resp; char nome[20];
	
	do
	{
		system ("color 3f"); // muda a cor do fundo
		system ("cls");
		printf("\n\t\t\t>>> ADIVINHE QUAL É A FRUTA <<<");
		printf("\n\t------------------------------------------------------------------------------\n");
		mostrar(nome);
		printf("\n\tESCOLHI UMA FRUTA, DESCUBRA QUAL É!\n\tHAHAHAHAHAHAHA\n");
		printf("\t------------------------------------------------------------------------------\n");
	    Dado vet[10] = {"\n\t0-MANGA\n", "\t1-BANANA\n", "\t2-LARANJA\n", "\t3-LIMAO\n", "\t4-UVA\n", "\t5-ABACAXI\n", "\t6-ABACATE\n", "\t7-PERA\n", "\t8-MAÇÃ\n", "\t9-GOIABA\n"};
	    int i, j, fruit;
	    srand((unsigned)time(NULL));
	    i = 1 + rand()%10;
    		for(j = 0; j < 10; j++){
        		printf("%s", vet[j].fruta);
   			}
	    printf("\n\tTente acertar o nome da fruta. Informe o numero: ");
	    scanf("%d", &fruit);
	    if(fruit > 0 && fruit < 10 ){
	   	printf("\n\tVoce escolheu %s", vet[fruit].fruta);
    	printf("\n\tA fruta era: %s", vet[i].fruta);
    	}
    	else{
		   	printf ("\n\t >> Opção Invalida <<");
	  	}
	    printf("\n\n\tVOCE DESEJA TENTAR OUTRA VEZ? (1)SIM  (2)NAO: ");
	    scanf("%d",&resp);
 	}
	while(resp == 1);

}
