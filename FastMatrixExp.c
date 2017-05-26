#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int m[1006][1006];

}Matriz;

Matriz mul(int n , Matriz* A, Matriz* B){
  int i , j , k;
  Matriz C;
    for(i = 0 ; i < n ; i++)
      for(j = 0 ; j < n ; j++){
        C.m[i][j] = 0;
        for(k = 0 ; k < n ; k++)
          C.m[i][j] = (C.m[i][j] + (A->m[i][k]%13 * B->m[k][j]%13)%13)%13;
      } 
      return C;
}

Matriz power(int n, Matriz base, long long int expo){
  int i , j;
  Matriz resp;

  for(i = 0 ; i < n ; i++)
    for(j = 0 ; j < n ; j++){
      if( i == j)
        resp.m[i][j] = 1;
      else
         resp.m[i][j] = 0;
    }

  while(expo > 0){
    if( expo%2 == 1)
      resp = mul(n, &resp, &base);
    base = mul(n, &base, &base);
    expo /= 2;
  }
  return resp;  
}
int main(){
  int i , j , n, quantos, l,p;
  long long int expo;
  Matriz base;

  scanf("%d %lld", &n, &expo);
  for(i = 0 ; i < n ; i++) for(j = 0 ; j < n ; j++) scanf("%d", &base.m[i][j]);
  base = power(n , base, expo);    
  scanf("%d", &quantos);
  for(i = 0 ; i < quantos; i++){
    scanf("%d %d", &l, &p);
    l--;
    p--;
    printf("%d\n",base.m[l][p]);
  }

