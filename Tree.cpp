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
void pre_order (node * root){
	if(root != NULL){
		printf("%d ",root->data);
		pre_order(root->FilhoE);
		pre_order(root->FilhoD);
	}
}
void in_order (node * root){
	if(root != NULL){
		pre_order(root->FilhoE);
		printf("%d ",root->data);
		pre_order(root->FilhoD);
	}
}
void pos_order (node * root){
	if(root != NULL){
		pre_order(root->FilhoE);
		pre_order(root->FilhoD);
		printf("%d ",root->data);
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
 	cout << "----SUA SOMA DAS FOLHAS EH " << soma << "----\n\n";
 	cout << "Pre order:\n";
 	pre_order(root);
 	cout << "\n\nIn order:\n";
 	in_order(root);
 	cout << "\n\nPos order:\n";
 	pos_order(root);

}
//Pre.: 9 6 5 7 11 10 12
//In..: 5 6 7 9 10 11 12
//Post: 5 7 6 10 12 11 9
