#include <stdio.h>
#include <stdlib.h>

void *buffer;
int *cp, *c;
float *a;
struct pessoa *pet;

struct pessoa{
char nome[20];
int idade, telefone;
};

void adicionar(){
	printf("Digite o Nome \n");
	scanf("%s", (pet+*cp)->nome);
	printf("Digite a idade\n");
	scanf("%d", & (pet+*cp)->idade);
	printf("Digite o Telefone\n");
	scanf("%d", & (pet+*cp)->telefone);
}


void realocar (){
    void *aux;
    aux=buffer;
	buffer = (void*)realloc (buffer , (sizeof (struct pessoa))*(*cp));
	cp=(int*)aux;
	c=(int*)cp+1;
	a= (float*)c+1;
	pet=(struct pessoa*)a+1;
	buffer = aux;
	printf (" Realioc OK \n");
}

void imprimirU (){}

void imprimirT (){
	for(int x=0;x<(*cp);x++){
		printf("Nome %s\n", (pet+x)->nome);
		printf("Idade %d\n", (pet+x)->idade);
		printf("Telefone %d\n", (pet+x)->telefone);
	}
}

int main(int argc, char **argv){

    buffer=malloc((2*sizeof(int))+sizeof(float)+sizeof(struct pessoa));
	cp= (int*) buffer;
	c=cp+1;
	a= (float*)c+1;
	pet=(struct pessoa*)a+1;
	*cp=0;

	//Menu
	for(*c=20;*c!=0;){
		printf (" Digite 1 para adicionar uma pessoa \n Digite 2 para imprimir uma pessoa\n");
		printf (" Digite 2 para imprimir uma pessoa\n");
		printf (" Digite 3 para imprimir tudo\n");
		printf (" Digite 4 para apagar o ultimo\n");
		printf (" Digite 0 para sair \n");
		scanf("%d",c);
//Adiciona UN
		if ( *c == 1 ) {
            (*cp)++;
            realocar ();
            (*cp)--;
			adicionar();
			*cp=*cp+1;
		}
//Imprime UN
		else if ((*c) == 2) {imprimirU ();}
//Imprime tudo
		else if ( (*c) == 3 ) {imprimirT ();}
//Apagar o ultimo
		else if ( *c == 4 ) {
			*cp=*cp-1;
			realocar ();
		}
//Sair
		else if ( *c == 0 ) { printf ("voce saiu");}
		else{printf ("numero errado tente denovo\n");}
	}
	free(buffer);

	return 0;
}
