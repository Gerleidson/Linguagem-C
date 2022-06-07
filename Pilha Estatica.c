//pilha estatico com 2 vetores, função mostrar vertical
//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Constantes
#define tamanho 5

//Estrutura da Pilha
struct tpilha {
 int vetor1[tamanho];
 int vetor2[tamanho];
 int aux[tamanho];
 int ini;
 int fim;
};

//Variáveis globais
struct tpilha pilha;
int op;

//Protipação
void pilha_empilhar();
void pilha_desempilhar();
void devolver();
void pilha_mostrar();
void pilha_mostrar2();
void menu_mostrar();

//Função principal
int main(){

 setlocale(LC_ALL, "Portuguese"); 
 op = 1; 
 pilha.ini = 0;
 pilha.fim = 0;
 while (op != 0) {
 	system("cls"); 
 	pilha_mostrar();
 	pilha_mostrar2();
 	menu_mostrar();
 	scanf("%d", &op);
 	switch (op) {
 		case 1:
 		pilha_empilhar();
 		break;
		case 2:
		pilha_desempilhar();
		break;
		case 3:
		devolver();
		break;
		} 
	}
	return(0);
}

//Adicionar um elemento no final da Pilha
void pilha_empilhar(){
	if (pilha.fim == tamanho) {
	 	printf("\nA pilha está cheia, impossível empilhar!\n\n");
 		system("pause"); 
 		} 
	else{
		printf("\nDigite o valor a ser empilhado: "); 
 		scanf("%d", &pilha.vetor1[pilha.fim]);
 		pilha.fim++; 
 		} 
}

//Retira o último elemento da Pilha 1 e incrementa na pilha 2
void pilha_desempilhar(){
 	if (pilha.ini == pilha.fim) {
 		printf("\nA pilha 1 está vazia, impossível desempilhar!\n\n");
 		system("pause"); 
 	} 
 else { 
 	pilha.vetor2[tamanho - pilha.fim] = pilha.vetor1[pilha.fim-1];
 	pilha.vetor1[pilha.fim-1] = 0;
 	pilha.fim--;
 	} 
}

//Retira o último elemento da Pilha 2 e incrementa na pilha 1
void devolver(){
 	if (pilha.fim >= tamanho) {
 	printf("\nA pilha 2 está vazia, impossível desempilhar!\n\n");
 	system("pause"); 
 	} 
 else {
	pilha.vetor1[pilha.fim] = pilha.vetor2[tamanho - pilha.fim-1];
	pilha.vetor2[tamanho - pilha.fim-1] = 0;
	pilha.fim++;
 	}
}

void pilha_mostrar() {
int i;
printf("Primeira Pilha\n\n");
for (i = 4; i>=0; i--) {
printf("%d \n", pilha.vetor1[i]);
}
printf("\n");
}



//Mostrar o conteúdo da segunda pilha
void pilha_mostrar2() {
int i;
printf("Segunda Pilha\n\n");
for (i = 4; i>=0; i--) {
printf("%d \n", pilha.vetor2[i]);
}
printf("\n");
}

//Mostrar o menu de opções
void menu_mostrar() {
	printf ("\n------------------------------------------------------ \n");
	printf ("Pratos a enfileirar: \n");
	printf ("\n1-Vermelho / 2-Verde / 3-Azul / 4-Branco / 5-Laranja\n");
	printf("\nEscolha uma opção:\n"); 
	printf("1 - Empilhar\n"); 
	printf("2 - Desempilhar pilha 1 para pilha 2\n"); 
	printf("3 - Desempilhar pilha 2 para pilha 1\n");
	printf("0 - Sair\n");
	printf("\nOpção: ");
}
