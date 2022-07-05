#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constantes
#define E 0
#define D 1
#define R -1

//Tipo nó
typedef struct NO {
	int dado;
	struct NO *esq;
	struct NO *dir;
	struct NO *pai;
} NO;

//Tipo árvore
typedef struct ARVORE{
	NO *raiz;
}ARVORE;

//Declaração da árvore
ARVORE a;

//Protótipos das funções
void inicializaArvore(ARVORE arv);
void inicializaNo(NO* n, int val);
void insereNoArvoreOrdenada(int valor);
void preOrdem(NO* raiz);
void emOrdem(NO* raiz);
void posOrdem(NO* raiz);
void busca(NO* raiz);
void menu();

//Função que sempre deve ser chamada ao se criar uma nova árvore
void inicializaArvore(ARVORE arv)
{
	arv.raiz = NULL;
}

//Função utilizada para inicializar um novo nó na árvore
void inicializaNo(NO* n, int val){
	if(!n)
	{
		printf("Falha de alocacao.\n");
		return;
	}
	n->pai = NULL;
	n->esq = NULL;
	n->dir = NULL;
	n->dado = val;
}

//Funçãoo que realiza a inserção de maneira ordenada
//Valores menores vão à esquerda
//Valores maiores ou iguais vão à direita
void insereNoArvoreOrdenada(int valor)
{
	NO* corrente = a.raiz;
	NO* pai;

	NO* novoNo = (NO*) malloc(sizeof(NO));
	inicializaNo(novoNo, valor);
	printf("Inserindo no %d. \n", novoNo->dado);
	
	if(corrente == NULL)
	{
		a.raiz = novoNo;
		printf("No inserido na raiz. \n");
		return;
	}
	
	while(corrente){
		pai = corrente;
		if(novoNo->dado < corrente->dado){
			corrente = corrente->esq;
			if(!corrente){
				printf("No inserido a esquerda do no %d. \n", pai->dado);
				pai->esq = novoNo;
				return;
			}
		}
		else{
			corrente = corrente->dir;
			if(!corrente){
				printf("No inserido a direita do no %d. \n", pai->dado);
				pai->dir = novoNo;
				return;
			}
		}
	}
}

//Executa o caminhamento pré-ordem a partir do nó indicado por "raiz"
void preOrdem(NO* raiz){
	if(raiz){
		printf("%d \t", raiz->dado);
		preOrdem(raiz->esq);
		preOrdem(raiz->dir);
	}
}

//Executa o caminhamento em-ordem a partir do nó indicado por "raiz"
void emOrdem(NO* raiz){
	if(raiz){
		emOrdem(raiz->esq);
		printf("%d \t", raiz->dado);
		emOrdem(raiz->dir);
	}
}

//Executa o caminhamento pos-ordem a partir do nó indicado por "raiz"
void posOrdem(NO* raiz){
	if(raiz){
		posOrdem(raiz->esq);
		posOrdem(raiz->dir);
		printf("%d \t", raiz->dado);
	}
}

//menu de opçoes solicita ao usuraio para digitar o seu RA e logo após a inserção dos numeros retorna ao menu onde o usuario escolhe o tipo de busca deseja imprimir na  tela
void menu(){
	int num,opc;
	
	while (opc < 4){
	printf("_______ARVOVE BINARIA_______\n\n");
	printf("0 - Digitar RA\n\n");
	printf("***TIPO DE BUSCA***\n");
	printf("1 - Pre ordem\n");
	printf("2 - Em ordem\n");
	printf("3 - Pos ordem\n");
	printf("4 - Encerrar arvore \n");
	printf("\nEscolha opcao: ");
	scanf ("%d", &opc);	
	switch (opc){
		case 0:
		 	for (int i = 0; i < 8; i++) {
		 		printf("\n\nDigite o %do numero do RA: \n", i+1);
		 		scanf("%d", &num);
				inicializaArvore(a);
				insereNoArvoreOrdenada(num);}
				system ("cls");
			break;
			
		case 1:	
			printf("\nBusca pre ordem: \n");
			preOrdem(a.raiz);
			printf("\n");
			system ("pause");
			system ("cls");
		break;
	
		case 2:
			printf("\nBusca em ordem: \n");
			emOrdem(a.raiz);
			printf("\n");
			system ("pause");
			system ("cls");
		break;
		
		case 3:
			printf("\nBusca pos ordem: \n");
			posOrdem(a.raiz);	
			printf("\n");
			system ("pause");
			system ("cls");
		break;
		case 4:
		break;
		}
	}
}


//chama função menu
int main(){
	menu();
}