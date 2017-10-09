
2 Types:


1-

long long pot(long long x, long long n, long long mod){
	long long ans = 1;
	while(n){
		if(n & 1) ans = (ans * x) % mod;
		x = (x * x) % mod;
		n >>= 1;
	}
	return ans;
}


2- O(Log(n))

int sq(int x){
	return x*x;
}

ll pot(ll b, ll n){
	if(n == 0) return 1;
	if(n&1) return b * pot(b,n-1);
	else return sq(pot(b,n/2));
}

