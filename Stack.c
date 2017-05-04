

typedef struct nodo{
   	char a;
   	char b;
   	char c;
   	char d;
    struct nodo* prox;
    struct nodo* ant;
}No;

typedef struct{
    No* prim;
    No* ult;
}pilha;

pilha* cria_pilha (void){
    pilha *l; 
    l = (pilha*) malloc(sizeof(pilha));
    l->prim = NULL;
    l->ult = NULL;
    return l;
}

bool pilha_vazia (pilha* l) {
    return (l->prim == NULL);
}

void empilha (pilha* l, char a, char b , char c , char d) {    /* insere no final */

    No *nodo; 

    nodo = (No*) malloc(sizeof(No));

    
    nodo -> a = a;
    nodo -> b = b;
    nodo -> c = c;
    nodo -> d = d;
    if(pilha_vazia(l)){
       
        l->ult = nodo;
        l->prim = nodo;
        nodo -> ant = NULL;
        nodo -> prox = NULL;
        
    }
    else{

        nodo->prox = NULL;

        nodo->ant = l -> ult;

        l->ult->prox = nodo;

        l->ult = nodo;
    }
}
void desempilha(pilha *l){
   	No * aux;
   	aux = l->ult;

    if(aux == l->ult && aux == l->prim){ /* apenas 1 elemento */
       
        l->ult = NULL;
        l->prim = NULL;
        free(aux);
        return;
    }

	l->ult->ant->prox = NULL;   
    l->ult = l->ult->ant;
    free(aux);
}

void pilha_libera(pilha *l){

    No *aux;

    aux = l->prim;

    for(;aux != l->ult; aux = aux->prox){
        pilha_remove(l, aux);
    }

    pilha_remove(l ,aux);

}
