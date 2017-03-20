long long pot(long long x, long long n, long long mod){
	long long ans = 1;
	while(n){
		if(n & 1) ans = (ans * x) % mod;
		x = (x * x) % mod;
		n >>= 1;
	}
	return ans;
}


