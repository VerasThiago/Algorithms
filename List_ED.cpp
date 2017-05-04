#include <bits/stdc++.h>
using namespace std;

typedef struct nodo{
    string nome;
    string resp;
    int len;
    struct nodo* prox;
    struct nodo* ant;    
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

void lista_insere (Lista* l, string nome, string resp) {    /* insere no inicio */

    No *nodo; 

    nodo = (No*) malloc(sizeof(No));

    nodo -> nome = nome;
    nodo -> resp = resp;
   // nodo -> len = len;
    if(lista_vazia(l)){
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
void imprimeLista(Lista * l){
   if(l->prim == NULL){
       printf("Lista Vazia\n");
    }
    else{
        No * p = l->prim;
       
       while(p != NULL){
           cout << p->nome << " " <<  p->len << endl;
          
          p = p->prox;
       }

     }
     
}

string busca ( string nome, Lista * l){
    No * aux = l->prim;
    if(aux == l->prim && aux -> nome == nome){
        //cout << (aux -> resp) << endl;
        return aux -> resp;
    }

    No* ant = NULL;

    while(aux -> nome != nome && aux -> prox != NULL){
        ant = aux;
        aux = aux -> prox;
    }
    if(aux -> nome != nome){
        //cout << "Nao tem no banco" << endl;
        return "Nao tem no banco";
    }
    ant -> prox = aux -> prox;
    aux -> prox = l -> prim;
    l->prim = aux;
    //cout  << (aux -> resp) << endl;
    return aux -> resp;

}
    
int main(){

    int n, k, m, i, j;
    string aux, sn;
    Lista *l = cria_lista();
   
    while(cin >> aux, aux != "FIM"){
        cin >> sn;
        //if(sn == "YES"){
            //k = aux.size();
            lista_insere(l,aux, sn);
        //}
    }

    cout << endl << endl << "Lista esta :" << endl << endl;
    
    imprimeLista(l);
    
    cout << endl;
    cout << "Quantas buscas?"
    cin >> n;
    
    for(int i = 0 ; i < n ; i++){
    	cin >> aux;
    	cout << busca(aux,l) << endl;
    	
    }
	
	cout << endl << endl << "Lista ficou :" << endl << endl;
    imprimeLista(l);
}
