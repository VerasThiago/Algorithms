#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct nodo{
    int info;
    struct nodo* prox;
    struct nodo* ant;
  
}No;

typedef struct{
    No* prim;
    No* ult;
}Fila;

Fila* cria_fila (void){
    Fila *f; 
    f = (Fila*) malloc(sizeof(Fila));
    f->prim = NULL;
    f->ult = NULL;
    return f;
}

bool fila_vazia (Fila* f) {
    return (f->prim == NULL);
}

void fila_insere (Fila* f, int valor) {    /* insere no final */

    No *nodo; 

    nodo = (No*) malloc(sizeof(No));

    nodo -> info = valor;
    
    nodo -> ant = NULL;

    if(fila_vazia(f)){
        f->ult = nodo;
        f->prim = nodo;

    }
    else{

        nodo -> prox = f->ult;

        f -> ult -> ant = nodo;

        f -> ult = nodo;
    }    

   
}

int fila_remove(Fila *f){ /* aux ponteiro pro no que deseja remover */
    if(fila_vazia(f)){
        printf("Vazia seu burro\n");
        return -1;
    }
    No *aux = f->prim;
    int r = aux->info;
    if(aux == f->ult){ /* apenas 1 elemento */
        f->ult = NULL;
        f->prim = NULL;
    } 
    else{
        f->prim = aux->ant;
        aux->ant->prox = NULL;
    }
    
    free(aux);
    return r;
}

void fila_libera(Fila *f){

    No *aux;
    aux = f->prim;
    while(!fila_vazia(f)) fila_remove(f);

  

}

int imprimeFila(Fila * f){
  if(f->prim == NULL){
       printf("Fila Vazia\n");
       return 0 ;
  }
  else{
      No * p = f->prim;
      int i  = 1;
     
       while(p != NULL){           
        printf("Pos: %d; Valor: %d\n",i++,p->info);
     
        p = p->prox;          
         
       }
       

  }

}

int main(){
 
    Fila *f = cria_fila();
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n ; i++){
        int x;
        scanf("%d", &x);
        fila_insere(f,x);
    }
    imprimeFila(f);
    printf("%d\n",fila_remove(f));
    

    return 0;
}
