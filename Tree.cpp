#include <bits/stdc++.h>

using namespace std;
struct node {
   int data;   
   struct node *FilhoE;
   struct node *FilhoD;
};


node* cria_tree (void){
    node *t; 
    t = (node*) malloc(sizeof(node));
    t->FilhoE = NULL;
    t->FilhoD = NULL;
    return t;
}

void insert(node *root, int data) {
	//if tree is empty, create root node
	struct node *tempNode = (struct node*) malloc(sizeof(struct node));
	tempNode->data = data;
	tempNode->FilhoE = NULL;
	tempNode->FilhoD = NULL;
	if(root == NULL) {
		root = tempNode;
		printf("base eh o %d\n", root->data);
	}
	else {
		if(data >= root->data){
			if(root->FilhoD == NULL)
				root->FilhoD = tempNode;
			else
				insert(root->FilhoD,data);
		}
		else{
			if(root->FilhoE == NULL)
				root->FilhoE = tempNode;
			else
				insert(root->FilhoE,data);
		}

	}
     
}
bool search(node *root,int data) {
	if(root == NULL) return false;

	if(data > root->data){
		if(root->FilhoD == NULL) return false;
		search(root->FilhoD,data);
	}
	else if( data < root->data){
		if(root->FilhoE == NULL) return false;
		search(root->FilhoE,data);
	}
	return true;
}

int main(){
	node *root = cria_tree();
	root = NULL;
	int n, x;
	cout << "Quantos numeros deseja inserir na arvore ? ";
	cin >> n;
	for(int i = 0 ; i < n ; ++i){
	  cin >> x;
	  insert(root,x);
	}
	cout << "Quer buscar quem ? ";
	cin >> x;
	cout << (search(root,x) ? "Achou":"Nao tem") << endl;
}
