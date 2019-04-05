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
	scanf("%s", & pet[*cp].nome[20]);
	printf("Digite a idade\n");
	scanf("%d", & pet[*cp].idade);	
	printf("Digite o Telefone\n");
	scanf("%d", & pet[*cp].telefone);
}

void realocar (){
	buffer = realloc (buffer , sizeof (struct pessoa)*(*cp));
	cp=buffer;
	c=cp+1;
	a= (float*)c+1;
	pet=(struct pessoa*)a+1;

}

void imprimirU (){
	
	
}

void apagar (){
	
	
}

void imprimirT (){
	for(*c=0;(*c)<=(*cp);(*c)++){
		printf("%s", & pet[*c].nome[20]);
		printf("%d", pet[*c].idade);
		printf("%d", pet[*c].telefone);

	}
	
}

int main(int argc, char **argv){

    buffer=malloc((2*sizeof(int))+sizeof(float)+sizeof(struct pessoa));
	cp=buffer;
	c=cp+1;
	a= (float*)c+1;
	pet=(struct pessoa*)a+1;
	*cp=0;

	//Menu
	for(*c=20;*c!=0;){
		printf (" Digite 1 para adicionar uma pessoa \n");
		printf (" Digite 2 para imprimir uma pessoa\n");
		printf (" Digite 3 para imprimir tudo\n");
		printf (" Digite 4 para apagar o ultimo\n");
		printf (" Digite 0 para sair \n");
		scanf("%d",c);
		if ( *c == 1 ) { 
			realocar ();
			adicionar();
			*cp=*cp+1;
		}
		if ( *c == 2 ) {imprimirU ();}
		if ( *c == 3 ) {imprimirT ();}
		if ( *c == 4 ) {apagar ();}
		if ( *c == 0 ) { printf ("voce saiu");}

		else{printf ("numero errado tente denovo\n");}
	}
	free (buffer);

	return 0;
}
