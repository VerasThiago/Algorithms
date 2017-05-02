#include <bits/stdc++.h>
using namespace std;

bool vazia = true;
int folhas_q = 0;
struct node {
   int data;   
   struct node *FilhoE;
   struct node *FilhoD;
};
void insert(node *root, int data) {
	//if tree is empty, create root node
	struct node *tempNode = (struct node*) malloc(sizeof(struct node));
	tempNode->data = data;
	tempNode->FilhoE = NULL;
	tempNode->FilhoD = NULL;
	
	if(vazia) {
		root->data = data;
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
	if(!vazia){
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
	node *root =  (node*) malloc(sizeof(node));	
	int n, x;
	cout << "Quantos numeros deseja inserir na arvore ? ";
	cin >> n;
	for(int i = 0 ; i < n ; ++i){
	  cin >> x;
	  insert(root,x);
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
