int seg[1000000];
int v[10000000];
void SegInit(int idx, int L, int R){
	if(L == R) seg[idx] = v[L];
	else{
		int mid = (L+R)/2;
		SegInit(idx*2,L,mid);
		SegInit((idx*2) + 1,mid+1, R);
		seg[idx] = seg[idx*2] + seg[(idx*2) + 1];
	}
}

int find(int idx, int L, int R, int S, int E){
	if(S <= L and R <= E) return seg[idx];
	if(L > E or S > R) return 0;
	return (find(idx*2, L, (L+R)/2, S, E) + find(idx*2 + 1, (L+R)/2 + 1, R, S, E));

}
void update(int idx, int L , int R,int valor, int quem){
	if( !(L <= quem and quem <= R) ) return;	
	seg[idx] -= valor;
	if(L == R) return;
	int mid = (L+R)/2;
	update(idx*2, L, mid, valor, quem);
	update(idx*2 + 1, mid+1, R, valor,quem);
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n ; i++) scanf("%d", v+i);
	SegInit(1,0,n-1);
	char op;
	int x;
	while(scanf(" %c %d", &op,&x) == 2){		
		if(op == '?')
			cout << find(1,0,n-1,0,x-2) << endl;
		else
			update(1,0,n-1,v[x-1],x-1);
	}
}
