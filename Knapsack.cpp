#include <bits/stdc++.h>
using namespace std;
#define N 1005
#define T 2005
#define ii pair<int,int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

int dp[N][T];
vector<ii> p(N);


int main(){
	int n, t;
	cin >> n >> t;

	for(int i = 1; i <= n ; i++){
		int x,y;
		cin >> x >> y;
		p[i] = mp(x,y);
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= t; j++){
			if(p[i].ff <= j) dp[i][j] = max( p[i].ss + dp[i][j - p[i].ff], dp[i-1][j]);
			else dp[i][j] = dp[i-1][j];
		}
	}
	cout << dp[n][t] << endl;

}
