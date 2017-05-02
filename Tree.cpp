#include <bits/stdc++.h>
using namespace std;

bool vazia = true;

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
	
	if(vazia) {
		root->data = data;
		printf("base eh o %d\n", root->data);
		vazia = false;
	}
	else {
		if(data >= root->data){
			if(root->FilhoD == NULL) root->FilhoD = tempNode;	
			
			else insert(root->FilhoD,data);
		}
		else{
			if(root->FilhoE == NULL) root->FilhoE = tempNode;				
			
			else insert(root->FilhoE,data);
		}
	}
     
}
bool search(node *root,int data) {
	if(root == NULL) return false;

	printf("to no %d\n",root->data);
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
int main(){
	node *root = cria_tree();
	
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
