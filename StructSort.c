#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct {
 	char pais[200];
 	int ouro, prata,bronze;
}selecao;

int cmp (const void *p1, const void *p2){
	selecao *a = (selecao*)p1;
	selecao *b = (selecao*)p2;

	if ( a->ouro > b->ouro)
		return 1;

	else if(a->ouro < b->ouro)
		return -1;

	else{ 
		if ( a->prata > b->prata)
			return 1;
		else if(a->prata < b->prata)
			return -1;
		else{
			if ( a->bronze > b->bronze)
				return 1;
			else if(a->bronze < b->bronze)
				return -1;
			else
				return strcmp(b->pais,a->pais);
		}
	}
}
int main (){
	int n, i;
		scanf("%d", &n);
			selecao v[n];
				for( i = 0 ; i < n ; i++){
					scanf(" %s %d %d %d", v[i].pais, &v[i].ouro, &v[i].prata, &v[i].bronze);
				}
				qsort(v,n,sizeof(selecao),cmp);
				for( i = n-1 ; i >= 0 ; i--)
				printf("%s %d %d %d\n", v[i].pais, v[i].ouro, v[i].prata, v[i].bronze);          
}
