vector<int> z_function(const string &s) {
    int n = s.size();
    vector<int> z(n, 0);
    int L = 0, R = 0;
    for(int i = 1; i < n; i++) {
        if(i <= R) {
            z[i] = min(z[i - L], R - i + 1);
        }
        while(z[i] + i < n && s[z[i] + i] == s[z[i]]) {
            z[i]++;
        }
        if(R < i + z[i] - 1) {
            L = i, R = i + z[i] - 1;
        }
    }
    return z;
}

// cada posição do vetor retornado é a maior subsequencia começado em i
/*   i    - 0 1 2 3 4 5 6 7 8 9
    S    - a b a c a b a b a c
    z[i] - 0 0 1 0 3 0 4 0 1 0
*/

//achar matching perfeito
int main(){
	string s , a;
	cin >> s >> a;
	int x = s.size();
	s += "#";
	s += a;
	int n = s.size();
	vector<int> v(n);
	v = z_function(s);
	int ans = 0;
	for(int i = x; i < n ; i++)	if(v[i] == x) ans++;
	cout << ans << endl;
	
}
