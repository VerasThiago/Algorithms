#include <bits/stdc++.h>
using namespace std;


typedef struct nodo {
   int data;   
   struct nodo *FilhoE;
   struct nodo *FilhoD;
}node;


node* cria_node(int data){
	node *tempNode = (node*) malloc(sizeof(node));
	tempNode->data = data;
	tempNode->FilhoE = NULL;
	tempNode->FilhoD = NULL;
	return tempNode;
}
node* insert (node *root, node *novo) {

    if (root == NULL) return novo;

    if (root->data > novo->data) 
       root->FilhoE = insert (root->FilhoE, novo);
    
    else 
       root->FilhoD = insert (root->FilhoD, novo);
    
    return root;
}
bool search(node *root,int data) {
	if(root == NULL) return false;

	printf("     To no %d\n",root->data);
	if(data > root->data){
		if(root->FilhoD == NULL)return false;
		return search(root->FilhoD,data);
	}
	else if( data < root->data){
		if(root->FilhoE == NULL) return false;
		return search(root->FilhoE,data);
	}
	return true;
}
void folhas(node*root, int &ans, int &soma){
	if(root != NULL){
		printf("     To no %d\n",root->data);
		if(root->FilhoD == NULL and root->FilhoE == NULL){
			printf("%d EH FOLHA, VIADO\n",root->data );
			soma+= root->data;
			ans++;
		}
		else{
			if(root->FilhoE != NULL)
				folhas(root->FilhoE,ans,soma);
			if(root->FilhoD != NULL)
				folhas(root->FilhoD,ans,soma);
		}
	}
	
}
int main(){
	node *root =  NULL;
	int n, x;
	cout << "Quantos numeros deseja inserir na arvore ? ";
	cin >> n;
	for(int i = 0 ; i < n ; ++i){
	  cin >> x;
	  node* aux = cria_node(x);
	  root = insert(root,aux);
	}
	cout << "Quer buscar quem ? ";
	cin >> x;
	cout << "\n\n    Buscando...\n" << endl;	
	cout << (search(root,x) ? "\n   --ACHOU--":"\n   --NAO TEM--") << endl;
	printf("\n\nContando as folhas...\n\n");
	int ans = 0, soma = 0;
	folhas(root,ans,soma);
 	cout << "\n  --TEM " << ans << " FOLHAS--\n\n" << endl;
 	cout << "----SUA SOMA DAS FOLHAS EH " << soma << "----\n\n\n\n";
}
