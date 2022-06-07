#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#define MAX 200
#include <conio.c>


//struct
struct ficha_projeto{
	int codigo, ano, status,quantidade;
	char titulo[50], descricao[200], gerente[50];
};

struct ficha_projeto projeto[MAX]; //variavel da struct

int cont = 0, quantidade = 0; // contadora

//prototipacao das funcoes
void abertura();
void menu();
void cadastro();
void listartodos();
void listarstatus();
void listarpor();
void listarfazer();
void listarfazendo();
void listarconcluido();
void listarporcodigo();
void listarporano();
void listargerente();
void listartitulo();
void imprimir (int pos);
void alterar();
void Excluir();

int main(){  // aqui começa o programa

	setlocale(LC_ALL, "portuguese");
	abertura();
    return 0;
}

void abertura(){ //tela de apresentação do programa
	system ("color 1f"); // muda a cor do fundo
	gotoxy(10,5); //necessita da biblioteca conio.c (posiciona texto em uma coluna e linha no terminal)
	printf (" *** DEVSOFT CONSULTORIA DE PROJETOS LTDA ***");
	printf ("\n\n\t BEM VINDO AO PROGRAMA DE CADASTRO DE PROJETOS!\n\t");
	printf ("\n\n\n\tEste software comercial é distribuído gratuitamente para uma avaliação,\n que expira após 200 cadastros.\n\n\n\n\n");
	printf ("\n\n\n\n\n\n Duvidas:\n Contato / Whatsapp: (71)99277-7540");
	printf ("\n E-mail: gerleidson.bomfim@gmail.com\n\n\n");
	system ("pause");
	menu();
}


void cadastro(){ //cadastro de projetos
	int resp;	
	gotoxy(10,5);
	//textbackground(RED);  //muda o fundo do texto para cor desejada
	textcolor(15);  //muda a cor do texto - existe uma tabela de cores 
	printf ("================= CADASTRO DE PROJETOS =============== \n\n");
	printf ("\tCódigo %d \n", cont + 1);
	getchar();
	printf ("\n\tDigite o titulo do projeto: "); 
	gets(projeto[cont].titulo);
	strupr(projeto[cont].titulo);
	printf ("\tDigite a descrição do projeto: ");
	gets(projeto[cont].descricao);
	strupr(projeto[cont].descricao);
	printf ("\tDigite o ano do projeto: ");
	scanf("%d", &projeto[cont].ano);
	fflush(stdin);
	printf ("\tDigite nome do gerente: ");
	fgets(projeto[cont].gerente, 50, stdin);
	strupr(projeto[cont].gerente);
	printf("\n\t=====================================================\n\n");
	printf ("	   	STATUS DO PROJETO	\n\n");
	printf("\t 1 - Fazer\n\t 2 - Fazendo\n\t 3 - Concluído\n\n");
	printf(" \tDigite o número do status desejado: ");
	scanf("%d",&projeto[cont].status);
	switch (projeto[cont].status){
		case 1:
			projeto[cont].status = 1;
			break;
		case 2:
			projeto[cont].status = 2;
			break;
		case 3:
			projeto[cont].status = 3;
		break;
		default:
			printf ("\n\t >> Opção Invalida <<");
	}	
	printf(" \n\n\tProjeto cadastrado com sucesso! ");
	projeto[cont].codigo = cont + 1;
	cont++;	//contador acrescenta 1 codigo em modo automatico
	quantidade++;	//contador acrescenta 1 projeto a cada cadastro	
	printf("\n\t=====================================================");
	printf("\n\n\tDigite: (1) - Novo cadastro	(2) - Voltar ao menu: ");
	scanf("%d",&resp);
	system("cls");
	switch (resp){
		case 1:
			cadastro();
			break;
		case 2:
		break;
		default:
			printf("\t<< Opção Inválida! >>\n");
			system("pause"); 
			system("cls");
	}
}

//lista todos os projetos cadastrados
void listartodos(){
	system("cls");
	gotoxy(10,5);
	int i;
	if (cont==0){
		printf ("\t >> Nenhum projeto cadastrado <<\n\n");
	}else{
		printf("================== LISTAR TODOS OS PROJETOS ================\n");
		for (i=0; i<cont; i++)
			imprimir (i);
	}
	system("pause");
	system("cls");
	listarpor();

}

//submenu para listar os projetos por categorias
void listarpor(){
	int resp;
	gotoxy(10,5);
	printf("===================== LISTAR PROJETOS POR ================\n\n");
	printf("\t1 - Todos \n");
	printf("\t2 - Status \n");
	printf("\t3 - Codigo \n");
	printf("\t4 - Ano \n");
	printf("\t5 - Gerente \n");
	printf("\t6 - Titulo \n");
	printf("\t7 - Voltar \n\n");
	printf("\tEscolha opção desejado: ");
	scanf ("%d", &resp);
	switch (resp){
	case 1:
		listartodos();	
		break;
	case 2:
		listarstatus();	
		break;
	case 3:
		listarporcodigo();
		break;
	case 4:
		listarporano();
		break;
	case 5:
		listargerente();	
	break;
	case 6:
		listartitulo();	
	break;
	case 7:
	system ("cls");}
	}

//lista projetos por status
void listarstatus(){
	int resp;
		system("cls");
		gotoxy(10,5);
		printf("============== LISTAR PROJETOS POR STATUS ================\n\n");
		printf("\t1 - Fazer\n \t2 - Fazendo\n \t3 - Concluído\n \t4 - Voltar ao menu\n\n");
		printf("\tEscolha a opção: ");
		scanf ("%d", &resp);
	switch (resp){
	case 1:
		listarfazer();	
		break;
	case 2:
		listarfazendo();
		break;
	case 3:
		listarconcluido();
		break;
	case 4:
	system ("cls");
	listarpor();}
}

// faz a busca dos dados cadastrados na struct e imprime na tela
void imprimir (int i){
	printf ("\n\t Código do Projeto: %d\n", projeto[i].codigo);
	printf ("\t Nome do Projeto: %s\n",projeto[i].titulo );
	printf ("\t Descrição do Projeto: %s\n", projeto[i].descricao);
	printf ("\t Ano do Projeto: %d\n", projeto[i].ano);
	printf ("\t Gerente: %s", projeto[i].gerente);
	printf ("\t Status do Projeto: %d\n", projeto[i].status);
	printf (" \n");
}
	

//lista projetos por status a fazer
void listarfazer(){
	int i, acha = 0;
		system ("cls");
		gotoxy(10,5);
		printf("====================== PROJETOS A FAZER ==================\n\n");
	for (i = 0; i < cont; i++){
		if (projeto[i].status == 1){
			imprimir (i);
			acha = 1;
		}
	}
	if (acha == 0){
		printf ("\t >> Nenhum projeto cadastrado <<\n\n");
	}
	system("pause");
	system("cls");
	listarstatus();
}

//lista projetos por status fazendo
void listarfazendo(){
	system("cls");
	int i,acha = 0;
	gotoxy(10,5);
		printf("===================== PROJETOS FAZENDO =================\n\n");
	for(i = 0; i < cont; i++){
		if(projeto[i].status == 2){
			imprimir (i);
			acha = 1;
		}
	}
	if (acha == 0){
		printf ("\t>> Nenhum projeto cadastrado <<\n\n");
	}
	system("pause");
	system("cls");
	listarstatus();
}

//lista projetos por status concluido
void listarconcluido(){
	int i, acha = 0;
		system("cls");
		gotoxy(10,5);
		printf("===================== PROJETOS CONCLUIDOS ==================\n\n");
	for(i = 0; i < cont; i++){
		if(projeto[i].status == 3){
	    	imprimir (i);
	    	acha = 1;
		}
	}
	if (acha == 0){
		printf ("\t >> Nenhum projeto cadastrado <<\n\n");
	}
	system("pause");
	system("cls");
	listarstatus();
}

//lista projetos por codigo
void listarporcodigo(){	
	int i,busca,acha,resp;
	system ("cls");
	gotoxy(10,5);
	printf("=========== LISTAR PROJETOS POR CODIGO ==========\n\n");
	printf("\t>>> Digite o codigo do projeto: ");
	scanf("%d",&busca);
	i = 0;
	acha = 0;
	while(i < cont){
		if (projeto[i].codigo == busca){
        	imprimir(i);
	    	acha = 1;
    	}
        i++;
	}
	if(acha == 0){	
    	printf ("\n\t >> Código não encontrado <<\n\n");
	}
	printf("\n\t=====================================================");
	printf("\n\n\tFazer nova busca?\n\t(1) - Sim	(2) - Não: ");
	scanf("%d",&resp);
	system("cls");
	switch (resp){
		case 1:
			listarporcodigo();
			break;
		case 2:
			listarpor();
		break;
		default:
			printf("\t<< Opção Inválida! >>\n");
			system("pause"); 
			system("cls");
	}
}

//lista projetos por ano
void listarporano(){	
	int i,busca,acha,resp;
	system("cls");
	gotoxy(10,5);
	printf("============ LISTAR PROJETOS POR ANO ===========\n\n");
	printf("\t>>> Digite o ano do projeto: ");
	scanf("%d",&busca);
	i = 0;
	acha = 0;
	while (i < cont){
    	if (projeto[i].ano == busca){
		    imprimir(i);
	    	acha = 1;
    	}
    	i++;
	}
	if(acha == 0){
    	printf("\n\t>> Nenhuma projeto cadastrado neste ano <<\n\n");
	}
	printf("\n\t=====================================================");
	printf("\n\n\tFazer nova busca?\n\t(1) - Sim	(2) - Não: ");
	scanf("%d",&resp);
	system("cls");
	switch (resp){
		case 1:
			listarporano();
			break;
		case 2:
			listarpor();
		break;
		default:
			printf("\t<< Opção Inválida! >>\n");
			system("pause"); 
			system("cls");
	}
}

//lista projetos por gerente
void listargerente(){
	int i, res, acha = 0,resp,tamanho;
	char gerente[20];
  	system("cls");
  	gotoxy(10,5);
  	printf("============ LISTAR PROJETO POR GERENTE ===========\n\n");
  	getchar();
	printf("\t>>> Digite o nome do gerente do projeto: ");
	fgets (gerente,20,stdin);
	strupr(gerente);
	tamanho = strlen(gerente);
	for(i=0; i<cont; i++){
		res = strncmp(gerente, projeto[i].gerente, tamanho-1);
		if (res == 0){
		    acha = 1;
			imprimir(i);
			}		
		if (acha==0){
			printf("\n\tGerente não encontrado");
			}
	}
	printf("\n\t=====================================================");
	printf("\n\n\tFazer nova busca?\n\t(1) - Sim	(2) - Não: ");
	scanf("%d",&resp);
	system("cls");
	switch (resp){
		case 1:
			listargerente();
			break;
		case 2:
			listarpor();
		break;
		default:
			printf("\t<< Opção Inválida! >>\n");
			system("pause"); 
			system("cls");}
}

//lista projetos por titulo
void listartitulo(){
	int i, res, acha = 0,resp,tamanho;
	char titulo[20];
  	system("cls");
  	gotoxy(10,5);
  	printf("============ LISTAR PROJETO POR TITULO ===========\n\n");
  	getchar();
	printf("\t>>> Digite o titulo do projeto: ");
	fgets (titulo,20,stdin);
	strupr(titulo);
	tamanho = strlen(titulo);
	for(i=0; i<cont; i++){
		res = strncmp(titulo, projeto[i].titulo, tamanho-1);
		if (res == 0){
		    acha = 1;
			imprimir(i);
			}		
		if (acha==0){
			printf("\n\tTitulo não encontrado");
			}
	}
	printf("\n\t=====================================================");
	printf("\n\n\tFazer nova busca?\n\t(1) - Sim	(2) - Não: ");
	scanf("%d",&resp);
	system("cls");
	switch (resp){
		case 1:
			listargerente();
			break;
		case 2:
			listarpor();
		break;
		default:
			printf("\t<< Opção Inválida! >>\n");
			system("pause"); 
			system("cls");}
}

//altera dados de um cadastro localizado por codigo
void alterar(){
	int i,busca,acha,resp,opcao;
	system ("cls");
	gotoxy(10,5);
	printf("=========== ALTERAR PROJETO ==========\n\n");
	printf("\t>>> Digite o codigo do projeto: ");
	scanf("%d",&busca);
	i = 0;
	acha = 0;
	while(i < cont){
		if (projeto[i].codigo == busca){
			imprimir(i);
			printf("\t===============================================\n\n");
        	printf ("\t1 - Titulo\n");
        	printf ("\t2 - Descrição\n");
        	printf ("\t3 - Ano\n");
        	printf ("\t4 - Gerente\n");
        	printf ("\t5 - Status\n");
        	printf ("\t6 - Cancelar alteração\n");
        	printf ("\n\tDigite opção desejado: ");
        	scanf ("%d", &opcao);
        	switch (opcao){
        		case 1:
	   				system ("cls");
    				gotoxy(10,5);
    				printf ("\t  >>> ALTERAR TITULO <<<\n"); 
					printf ("\n\tDigite novo titulo do projeto: ");
    				fflush (stdin);
    				gets(projeto[i].titulo);
    				printf ("\n\tNovo titulo do projeto: %s\n",projeto[i].titulo);
        			break;
        		case 2:
   					system ("cls");
   					gotoxy(10,5);   
    				printf ("\t>>> ALTERAR DESCRIÇÃO <<<\n");
    				printf ("\n\tDigite nova descrição do projeto: ");
    				fflush (stdin);
    				gets(projeto[i].descricao);
    				printf ("\n\tNova descrição do projeto:  %s\n",projeto[i].descricao);
					break;
        		case 3:
       				system ("cls");
    				gotoxy(10,5);
    				printf ("\t>>> ALTERAR ANO <<<\n");
    				printf ("\n\tDigite novo ano do projeto: ");
    				fflush (stdin);
    				scanf ("%d",&projeto[i].ano);
    				printf ("\n\tNovo ano do projeto:  %d\n",projeto[i].ano);
           			break;
        		case 4:       			
    				system ("cls");
    				gotoxy(10,5);
    				printf ("\t>>> ALTERAR GERENTE <<<\n");
    				printf ("\n\tDigite novo gerente do projeto: ");
    				fflush (stdin);
    				gets(projeto[i].gerente);
    				printf ("\n\tNovo gerente do projeto:  %s\n",projeto[i].gerente);
           			break;
        		case 5:
    				system ("cls");
    				gotoxy(10,5);
    				printf ("\t>>> ALTERAR STATUS <<<\n\n");
					printf ("\t1 - Fazer\n	2 - Fazendo\n	3 - Concluido\n");
    				printf ("\n\tDigite novo status do projeto: ");
    				fflush (stdin);
    				scanf ("%d",&projeto[i].status);
    				printf ("\n\tNovo status do projeto:  %d\n",projeto[i].status);
    	 			break;
    	 		case 6:
    	  		break;}		
        		
	    	acha = 1;
    	}
        i++;
	}
	if(acha == 0){	
    	printf ("\n\n\t >> Alteração realizada com sucesso <<\n");
	}
	printf("\n\t====================================================");
	printf("\n\n\tAlterar outro projeto?\n\t(1) - Sim	(2) - Não: ");
	scanf("%d",&resp);
	system("cls");
	switch (resp){
		case 1:
			alterar();
			break;
		case 2:
		break;
		default:
			printf("\t<< Opção Inválida! >>\n");
			system("pause"); 
			system("cls");}
}

// deleta um projeto por codigo
void Excluir(){
	int pos;
	char opc;
	gotoxy(10,5);
	printf("============= EXCLUIR CADASTRO ===========\n");
	printf ("\n\tDigite o codigo do projeto: ");
	scanf("%d", &pos);
	imprimir (pos - 1);
	printf(" Deseja Excluir? S/N: ");
	getchar();
	opc = toupper(getchar());
	if (opc == 'S'){
		while (pos < cont){
			projeto[pos-1].codigo = projeto[pos].codigo;	
			projeto[pos-1].codigo = pos;
			pos++;
		}
		cont --; //diminue um codigo
		quantidade--; //diminue um projeto cadastrado
		menu();
	}else{
		printf("\n\t >> Exclusão cancelado <<\n\n");
		system("pause");
		system("cls");
	}
}
	
// menu principal
void menu(){
	int num;
	num = 0;
	do{
		system("cls");
		gotoxy(10,5);
		printf("\t============== MENU PRINCIPAL ===============\n\n");
		printf("\t %d PROJETOS CADASTRADOS\n\n",quantidade);
		printf("\t 1 - Cadastrar projeto \n");
		printf("\t 2 - Listar projetos por \n");
		printf("\t 3 - Alterar projeto \n");
		printf("\t 4 - Excluir Projeto \n");
		printf("\t 5 - Sair \n\n");
		printf("\t Digite o numero desejado: ");
		scanf ("%d", &num);
		system("cls");
		switch (num){
			case 1:
				if (cont > 200)
					printf ("\t>> Limite atingindo! <<");
				else
					cadastro();	
			break;   	
			case 2:
				listarpor();
			break;   	
			case 3:
				alterar(); 
			break;
			case 4:
				Excluir(); 
			break;
		    case 5:
		    	gotoxy(10,5);
		    	printf ("\n\t-----------------------------------\n\n"); 
		    	printf ("\n\tDesenvolvedor: Gerleidson A. Bomfim\n\n"); 
		    	printf ("\n\t\tFechando o programa\n\n"); 
			break;		    	
			default:
				printf("\t>> Opção Inválida <<\n\n");
				system("pause");
				system("cls");
		}
	}while(num != 5);
}
