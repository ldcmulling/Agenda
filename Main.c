#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *buffer;
struct variavel *var;
struct pessoa *pet;

struct variavel{
int cp, c, i, j;
char temp[20];
};

struct pessoa{
char nome[20];
int idade, telefone;
};

void adicionar(){
	printf("Digite o Nome \n");
	scanf("%s", (pet+var->cp)->nome);
	printf("Digite a idade\n");
	scanf("%d", & (pet+var->cp)->idade);
	printf("Digite o Telefone\n");
	scanf("%d", & (pet+var->cp)->telefone);
}

void realocar (){
	if ((buffer = (void*)realloc (buffer , (sizeof(struct variavel)+(sizeof(struct pessoa)*(var->cp+1))))) == NULL)	printf("Memoria nao alocada ERRO\n");
	var= buffer;
	pet=(var +1);
	printf (" Realioc OK \n\n");
}

void delete(){
	printf (" Digite o nome da pessoa\n");
	scanf(" %s" , var->temp);
	for(var->i=0,var->j=0;var->i<var->cp;var->i++){
		if (strcmp(var->temp,(pet+var->i)->nome) == 0){
			for(var->j=var->i;var->j<var->cp;var->j++){
				*(pet+var->j)->nome = *(pet+(var->j+1))->nome ;
				(pet+var->j)->idade	= (pet+(var->j+1))->idade;
				(pet+var->j)->telefone = (pet+(var->j+1))->telefone;
			}
			var->cp=var->cp-1;
			realocar ();
			if (strcmp(var->temp,(pet+(var->i))->nome) == 0){var->i--;}
		}
	}
	if (var->j==0){printf("Nome nao encontrado\n\n");}
}

void imprimirT (){
	for(var->i=0;var->i<(var->cp);(var->i)++){
		printf("Nome %s\n", (pet+var->i)->nome);
		printf("Idade %d\n", (pet+var->i)->idade);
		printf("Telefone %d\n", (pet+var->i)->telefone);
	}
}


int main(int argc, char **argv){
	if((buffer= malloc(sizeof(struct variavel)))== NULL){
		printf("Memoria nao alocada ERRO\n");
    return -1;
	}
	var= buffer;
	var->cp=0;

	//Menu
	for(var->c=20;var->c!=0;){
		printf (" Digite 1 para adicionar uma pessoa\n");
		printf (" Digite 2 para imprimir tudo\n");
		printf (" Digite 3 para apagar uma pessoa\n");
		printf (" Digite 4 para apagar o ultimo\n");
		printf (" Digite 0 para sair \n");
		scanf("%d", & var->c);
//Adiciona UN
		if ( var->c == 1 ) {
            realocar ();
			adicionar();
			var->cp=var->cp+1;
		}
//Imprime tudo
		else if ( (var->c) == 2 ) {imprimirT ();}
//Pesquisar e Apagar
		else if ( var->c == 3 ) {
			delete();
		}
//Apagar o ultimo
		else if ( var->c == 4 ) {
			var->cp=var->cp-1;
			realocar ();
		}
//Sair
		else if ( var->c == 0 ) { printf ("voce saiu");}
		else{printf ("numero errado tente denovo\n");}
	}
	free(buffer);
	
	return 0;
}
