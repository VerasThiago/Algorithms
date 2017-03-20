
#include <iomanip>
#include <map>
#include <string>
#include <cstdio>
#include <set>
#include <vector>
#include <stack>
#include <list>
#include <algorithm>
#include <string.h>
#include <stdlib.h>

using namespace std;

typedef struct {
    int info;
    struct nodo* prox;
  
}No;

typedef struct{
    No* prim;
    No* ult;
}Lista;

Lista* cria_lista (void){
    Lista *l; 
    l = (Lista*) malloc(sizeof(Lista));
    l->prim = NULL;
    l->ult = NULL;
    return l;
}

bool lista_vazia (Lista* l) {
    return (l->prim == NULL);
}

void lista_insere (Lista* l, int valor) {    /* insere no inicio */

    No *nodo; 

    nodo = (No*) malloc(sizeof(No));

    nodo -> info = valor;

    if(lista_vazia(l)){
        l->ult = nodo;
        l->prim = nodo;
    }

    nodo->prox = l->prim;

    nodo->ant = l->ult;

    l->prim->ant = nodo;

    l->prim = nodo;

    l->ult->prox = l->prim;

}

void lista_remove(Lista *l, No *aux){ /* aux ponteiro pro no que deseja remover */
    
    if(aux == l->ult && aux == l->prim){ /* apenas 1 elemento */
        l->ult == NULL;
        l->prim == NULL;
        free(aux);
        return;
    }

    if(aux == l->ult){
        l->ult = aux->ant;
    }
    else if(aux == l->prim){
        l->prim = aux->prox;
    }

    aux->ant->prox = aux->prox;

    aux->prox->ant = aux->ant;

    free(aux);
}

void lista_libera(Lista *l){

    No *aux;

    aux = l->prim;

    for(;aux != l->ult; aux = aux->prox){
        lista_remove(l, aux);
    }

    lista_remove(l ,aux);

}

int main(){

    int n, k, m, i, j;
        
    Lista *l = cria_lista();

    while(cin >> n >> k >> m, n){

        for(i = n; i > 0; i--){
            lista_insere(l,i);
        }

        No *aux1;
        No *aux2;

        aux1 = l->prim;
        aux2 = l->ult;

        int cont = 0;

        while(cont < n){

            int j;

            for(j = 1; j < m; j++){
                aux2 = aux2 -> ant;
            }

            for(j = 1; j < k; j++){
                aux1 = aux1 -> prox;
            }

            if(aux1 == aux2){
                if(cont == n-1){
                    if(aux1->info < 10) printf("  %d",aux1->info );
                    else if(aux1->info >= 10 && aux1->info < 100) printf(" %d",aux1->info );
                    else printf("%d",aux1->info );
                }
                else{
                    if(aux1->info < 10) printf("  %d,",aux1->info );
                    else if(aux1->info >= 10 && aux1->info < 100) printf(" %d,",aux1->info );
                    else printf("%d,",aux1->info );
                }

                lista_remove(l,aux1);
                cont++;
            }



            else{
                
                if(aux1->info < 10) printf("  %d",aux1->info );
                else if(aux1->info >= 10 && aux1->info < 100) printf(" %d",aux1->info );
                else printf("%d",aux1->info );
                
                if(cont == n-2){
                    if(aux2->info < 10) printf("  %d",aux2->info );
                    else if(aux2->info >= 10 && aux2->info < 100) printf(" %d",aux2->info );
                    else printf("%d",aux2->info );
                }
                
                else{
                    if(aux2->info < 10) printf("  %d,",aux2->info );
                    else if(aux2->info >= 10 && aux2->info < 100) printf(" %d,",aux2->info );
                    else printf("%d,",aux2->info );
                }

                lista_remove(l,aux1);
                if(aux1->prox == aux2) aux1->prox = aux2->prox; /* condicao de contorno */
                lista_remove(l,aux2);
                cont += 2;
            }

            aux1 = aux1 ->prox;

            aux2 = aux2 ->ant;
            
        }

        cout << endl;
    }

    return 0;
}