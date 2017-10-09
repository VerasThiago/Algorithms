bool isPrime(long long int n){
    int i;

    if(n==2)
        return true;

    if(n%2==0)
        return false;

    for(i=3;i<=sqrt(n);i+=2)
        if(n%i==0)
            return false;

    return true;
}

// Eratóstenes algorithm

vector<bool> prime(N, true);
for(int i = 2; i <= sqrt(N); ++i){
	if(!prime[i]) continue;
	for(int k = i+i; k <= N; k += i) prime[k] = false;
} 
