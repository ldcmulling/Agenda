#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *buffer;
int *cp, *c;
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
	buffer = (void*)realloc (buffer , (2*sizeof(int)+ sizeof (struct pessoa))*(*cp+1));
	cp=(int*)buffer;
	c=(int*)cp+1;
	pet=(struct pessoa*)c+1;
	printf (" Realioc OK \n\n");
}

void delete(){
	char temp[20];
	int y=0;
	printf (" Digite o nome da pessoa\n");
	scanf(" %s" , temp);
	for(int x=0;x<*cp;x++){
		if (strcmp(temp,(pet+x)->nome) == 0){
			for(y=x;y<*cp;y++){
				*(pet+y)->nome = *(pet+(y+1))->nome ;
				(pet+y)->idade	= (pet+(y+1))->idade;
				(pet+y)->telefone = (pet+(y+1))->telefone;
			}
			*cp=*cp-1;
			realocar ();
		}
	}
	if (y==0){printf("Nome nao encontrado\n\n");}
}

void imprimirT (){
	for(int x=0;x<(*cp);x++){
		printf("Nome %s\n", (pet+x)->nome);
		printf("Idade %d\n", (pet+x)->idade);
		printf("Telefone %d\n", (pet+x)->telefone);
	}
}

int main(int argc, char **argv){
	buffer=malloc((2*sizeof(int))+sizeof(struct pessoa));
	cp= (int*) buffer;
	c=(int*)cp+1;
	pet=(struct pessoa*)c+1;
	*cp=0;

	//Menu
	for(*c=20;*c!=0;){
		printf (" Digite 1 para adicionar uma pessoa\n");
		printf (" Digite 2 para imprimir tudo\n");
		printf (" Digite 3 para apagar uma pessoa\n");
		printf (" Digite 4 para apagar o ultimo\n");
		printf (" Digite 0 para sair \n");
		scanf("%d",c);
//Adiciona UN
		if ( *c == 1 ) {
            realocar ();
			adicionar();
			*cp=*cp+1;
		}
//Imprime tudo
		else if ( (*c) == 2 ) {imprimirT ();}
//Pesquisar e Apagar
		else if ( *c == 3 ) {
			delete();
		}
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
