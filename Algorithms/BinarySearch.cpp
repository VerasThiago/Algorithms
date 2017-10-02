#include <bits/stdc++.h>

using namespace std;

bool PesquisaBinaria ( int k[], int who , int n){
	int inf,sup,meio;
	inf=0;
	sup=n-1;
	while (inf<=sup)
	{
	  meio=(inf+sup)/2;
	  if (who==k[meio])
	       return true;
	  else if (who<k[meio])
	       sup=meio-1;
	  else
	       inf=meio+1;
	}
	return false;  
}

int IterativeBinaryS(int v[], int x , int n){
	int L = 0, R = n-1;
	bool ans = false;
	for(int i = 0 ; i < 100; i++){
		int mid = (L+R)/2;
		if(v[mid] == x) return true;
		else if(v[mid] > x) R = mid-1;
		else L = mid + 1;
	}
	return false;
}

int main(){
	int x,n;
	printf("Tamanho do vetor: ");
	cin >> n;
	int v[n];
	printf("Digite os valores do vetor\n");
	for(int i = 0; i < n ; i++) scanf("%d", v+i);
	printf("Qual numero deseja buscar?\n");
	scanf("%d", &x);
	printf("%s\n", IterativeBinaryS(v,x,n) ? "Achou":"Nao achou");
	printf("%s\n", PesquisaBinaria(v,x,n) ? "Achou":"Nao achou");

}