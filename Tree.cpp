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
node *root = cria_tree();

void insert(int data) {
   struct node *tempNode = (struct node*) malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;

   tempNode->data = data;
   tempNode->FilhoE = NULL;
   tempNode->FilhoD = NULL;

   //if tree is empty, create root node
   if(root == NULL) {
      root = tempNode;
   } else {
      current = root;
      parent  = NULL;

      while(1) {                
         parent = current;

         //go to left of the tree
         if(data < parent->data) {
            current = current->FilhoE;                
            
            //insert to the left
            if(current == NULL) {
               parent->FilhoE = tempNode;
               return;
            }
         }
			
         //go to right of the tree
         else {
            current = current->FilhoD;
            
            //insert to the right
            if(current == NULL) {
               parent->FilhoD = tempNode;
               return;
            }
         }
      }            
   }
}
bool search(int data) {
   struct node *current = root;
   printf("Visiting elements: ");

   while(current->data != data) {
      if(current != NULL)
      printf("%d ",current->data); 
      
      //go to left tree

      if(current->data > data) {
         current = current->FilhoE;
      }
      //else go to right tree
      else {                
         current = current->FilhoD;
      }

      //not found
      if(current == NULL) {
         return false;
      }

      return true;
   }  
}

int main(){
   root = NULL;
   int n, x;
   cout << "Quantos numeros deseja inserir na arvore ? ";
   cin >> n;
   for(int i = 0 ; i < n ; ++i){
      cin >> x;
      insert(x);
   }
   cout << "Quer buscar quem ? ";
   cin >> x;
   cout << (search(x) ? "Achou":"Nao tem") << endl;
}
