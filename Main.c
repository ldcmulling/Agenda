#include <stdio.h>
#include <stdlib.h>

struct pessoa{
char nome[20];
int idade, telefone;
};

void adicionar(int *cp,struct pessoa *pet){
	printf("Digite o Nome \n");
	scanf("%s", & pet->nome[20]);
	printf("Digite a idade\n");
	scanf("%d", & pet->idade);	
	printf("Digite o Telefone\n");
	scanf("%d", & pet->telefone);
}

void realocar (struct pessoa *pet; void *buffer){
//	void *buf;
//
//	buf=realloc(buffer,);

//	cp=buffer;
//	c=cp+1;
//	a= (float*)c+1;
//	pet=(struct pessoa*)a+1;



}

int main(int argc, char **argv){
    void *buffer;
    int *cp, *c;
    float *a;
    struct pessoa *pet;
    
    buffer=malloc(2*sizeof(int)+sizeof(float)+sizeof(struct pessoa));
	cp=buffer;
	c=cp+1;
	a= (float*)c+1;
	pet=(struct pessoa*)a+1;
	*cp=1;
	
	//Menu
	for(*c=20;*c!=0;){
		printf (" Digite 1 para adicionar uma pessoa \n");
		printf (" Digite 0 para sair \n");
		scanf("%d",c);
		
		if ( *c == 1 ) { 
			realocar (pet,buffer);
			adicionar(cp,pet);
			*cp++;
			}
		if ( *c == 0 ) { printf ("voce saiu");}
		else{printf ("numero errado tente denovo\n");}
}
	
	free (buffer);

	return 0;
}
