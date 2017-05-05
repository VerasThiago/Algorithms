#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0 ; i < n ; i++)
		cin >> v[i];
	int ans = 0, temp = 0;

	for(int i = 0 ; i < n ; i++){
		temp+=v[i];
		ans = max(ans,temp);
		if(temp < 0) temp = 0;
	}
	cout << ans << endl;
		    

    return 0;
}
