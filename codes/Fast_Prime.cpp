bool isPrime(long long int n){  // Sqrt(n) for 1 prime
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

// Eratóstenes algorithm n*log(log(n)) for n primes

vector<bool> prime(N, true);     //
for(int i = 2; i <= sqrt(N); ++i){
	if(!prime[i]) continue;
	for(int k = i+i; k <= N; k += i) prime[k] = false;
} 


// O(n) for n primes
vector <int> sieve (int n) {
    vector <int> prime;
    bool is_composite[N];
    int func[N], cnt[N];
	fill (is_composite, is_composite + n, false);
	func[1] = 1;
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) {
			prime.push_back (i);
			func[i] = 1; cnt[i] = 1;
		}
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) {
				func[i * prime[j]] = func[i] / cnt[i] * (cnt[i] + 1);
				cnt[i * prime[j]] = cnt[i] + 1;
				break;
			} else {
				func[i * prime[j]] = func[i] * func[prime[j]];
				cnt[i * prime[j]] = 1;
			}
		}
	}
    return prime;
}