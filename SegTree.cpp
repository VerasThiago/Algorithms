#include <bits/stdc++.h>

using namespace std;

#define N (int) 4e5

vector <ii> seg(N);
int v[N];

void init(int idx, int L, int R){
	if(L == R) seg[idx] = v[L],v[L];
	else{
		int mid = (L+R)/2;
		init(idx*2, L, mid);
		init(idx*2 + 1, mid+1, R);
		seg[idx].ff = max(seg[idx*2].ff,seg[idx*2+1].ff);
		seg[idx].ss = min(seg[idx*2].ss,seg[idx*2+1].ss);
	}
}


int main(){
	int n;
	cin << n;
	for(int i = 0; i < n; i++) scanf("%d", v+i);
	int op, i, k;
	init(1,0,n-1);
	for(int i = 0; i < N; i++){
		if(seg[i].ff == 0) continue;
		printf("Seg[%d] - Max = %d Min = %d\n",%d,seg[%d].ff,seg[%d].ss );
	}
	/*
	while(scanf("%d %d %d", &op, &i, &j)){
		if(op == 2) printf("%d\n",find(1,0,n-1,i,j));
		else update(1,0,n-1,i,j);
	}*/


}