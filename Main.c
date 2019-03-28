
#include <stdio.h>
#include <stdlib.h>

struct pessoa{
char nome[20];
int idade, telefone;
};

void adicionar(int *c,struct pessoa *pet){
	for(*c=1;*c!=0;){
		printf (" Digite 1 para adicionar \ Digite 0 para sair \n");
		scanf("%d",c);
		printf("Digite o Nome \n");
		scanf(" %s ", pet->nome);
		printf("Digite a idade\n");
		scanf(" %d ", pet->idade);	
		printf("Digite o Telefone\n");
		scanf(" %d ", pet->telefone);
		
	}
}



int main(int argc, char **argv){
    void *buffer;
    int *cp, *c;
    float *a;
    struct pessoa *pet;
    
	printf("debug\n");
	
	printf("debug\n");
    buffer=malloc(2*sizeof(int)+sizeof(float)+sizeof(struct pessoa));
	cp=buffer;
	c=cp+1;
	a= (float*)c+1;
	pet=(struct pessoa*)a+1;
	*cp=0;
	
	adicionar(c,pet);
	
	printf("debug\n");

	return 0;
}
