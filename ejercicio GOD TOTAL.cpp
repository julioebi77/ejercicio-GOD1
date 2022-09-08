#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct{
	int Edad;
	char nom[20];
	char ape[20];
	char tel[12];
}t_elemento;
struct pila{
	t_elemento dato;
	struct pila *sig;
};
typedef struct pila t_pila;
typedef t_pila *ptr_pila;
void insertar(ptr_pila *,t_elemento);
void extraer(ptr_pila *);
void visualizar(t_pila *);
int main(){
	t_pila *L=NULL;
	t_elemento N;
	char opc=' ';
	
	do
    {
    	printf("\t0.- Buscar\n");
    	
        printf("\t1.- Insertar\n");

        printf("\t2.- Extraer\n");

        printf("\t3.- Visualizar la Lista\n");

        printf("\t4.- Salir\n");
        opc=getch( );
        system("cls");
        switch(opc)
        {
            case '1':
                  {
                printf("\nDigite su edad : ");
                scanf("%d", &N.Edad);
                printf("\ningrese su Nombre :");
                  scanf("%s", &N.nom);
                printf("\ningrese su Apellido :");
                  scanf("%s", &N.ape);
                printf("\ningrese su telefono :");
                  scanf("%s", &N.tel);
                insertar(&L,N); }
                break;
            case '2':
                if (L==NULL){
                   printf("\n\nNo existen datos a visualizar...\n");
                   getch(); }
                else
                   extraer(&L);
                break;
            case '3':
            	if (L==NULL){
                   printf("\n\nNo existen datos a visualizar...\n");
                   getch();}
                visualizar(L);
        }
    }while (opc!='4');
}
void insertar(ptr_pila *Q,t_elemento X){;
	t_pila *aux;
	aux=(t_pila *)malloc(sizeof(struct pila));
	aux->dato= X;
	if((*Q)==NULL){
		(*Q)=aux;
		aux->sig=NULL;
	}else{
		aux->sig=(*Q);
		(*Q)=aux;
	}
}
void extraer(ptr_pila *Q)
{
   t_pila *AUX;

   if (Q!=NULL)
     { 
	AUX=(*Q);
    (*Q)=(*Q)->sig;
    free(AUX);
    printf("\n\nExtraccion realizada...., pulse una tecla\n");
	}
   system("pause");
}
void visualizar (t_pila *Q){
	FILE *Ar;
	Ar = fopen("datos.dat","w");
	if(Ar==NULL){
		printf("\n\n ERROR EN LA APERTURA");
	}
	system("cls");
	printf("\n\nDatos a ser grabados en el archivo\n\n");
	printf("\n\tEDAD\t\tNOMBRE\t\tAPELLIDO\tTELEFONO\n\n");
	fprintf(Ar,"\n\tEDAD\t\tNOMBRE\t\tAPELLIDO\tTELEFONO\n\n");
	while (Q !=NULL)
	{
		printf("\n%11d%17s%17s%20s\n\n",Q->dato.Edad,Q->dato.nom,Q->dato.ape,Q->dato.tel);
		fprintf(Ar,"\n%11d%17s%17s%20s\n\n",Q->dato.Edad,Q->dato.nom,Q->dato.ape,Q->dato.tel);
		Q =Q->sig;
	}
}
