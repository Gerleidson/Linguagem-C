#include <stdio.h>
#include <stdlib.h>

int main(){
int anoatual,anonascimento,idade;

printf("informe ano atual: "); scanf("%d",&anoatual);
printf("informe ano de nascimento: ");scanf("%d",&anonascimento);
while (anonascimento > 0 ) {//anonascimento != 0
    idade = anoatual - anonascimento;
    printf("Idade %d\n",idade);
    printf("Informe ano nascimento");
    scanf("%d",&anonascimento);
	}
}

