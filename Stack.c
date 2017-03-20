#include <stdio.h>
#include <stdbool.h>
#define MAX 10000

int pilha[MAX];
int top = -1;

int push(int val){
	if(top < MAX - 1){
		top++;
		pilha[top] = val;
	}
	else return printf("Can't push\n");

	return -1;
}

void pop(){
	if(top != -1)
		top--;
	else  printf("Can't pop\n");
}

void check(){
	printf("Num of top: %d\n",pilha[top]);
}





int main(){
	int  i, n=1, count, x=1, aux, j = 1 ;
	bool ans = true;
		
		while(n){
			scanf("%d", &n);
			if(!n)
				return 0;

			int comp[n];
			while(x){
				
				scanf("%d", &comp[0]);
				if(comp[0] == 0)
					break;
				else
					for(i = 1 ; i < n ; i++){
						scanf("%d", &comp[i]);
					}

				aux = 1;			
				count = 0;
				top = -1;
				push(1);
				while(j){					
				
					if(count == n - 1){
						ans = true;
						break;
					}	
					if(pilha[top] == comp[count]){
						count++;
						pop();
						if(top == -1){
							aux++;
							push(aux);
						}

					}
					else{						
						aux++;
						if(aux == n+1){
							ans = false;
							break;	
						}						
						push(aux);
					}
					

				}
				if(ans)
					printf("Yes\n");
				else
					printf("No\n");
								
			}
			printf("\n");	
				

		}



	




	return 0;
}