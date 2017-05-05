#include <bits/stdc++.h>

using namespace std;

int const mod = 1e9+7;
int main(){
	string a;
	int ans = 0;
	a += "x";
	cin >> a;
	a += "x";
	int cont_a = 0;
	for(int i = 1 ; i < a.size()-1; i++){
		if(a[i] == 'b' and a[i-1] == 'a'){
			if(a[i-2] == 'a') ans = (ans + 3)%mod;
			else ans = (ans + 1) %mod;
			a[i] = 'a';
			a[i-1] = 'b';	
		}
	}
	cout << ans << endl;

}


