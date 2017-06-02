Longest Palindromic Subsequence
int dp[MAX][MAX];

int main(){
	int x;
	cin >> x;
	while(x--){
		string a;
		cin >> a;
		int n = a.size();
		for(int i = 0 ; i < n ; i++) for(int j = 0 ; j < n ; j++) dp[i][j] = 0;
		for(int i = 0 ; i < n ; i++) dp[i][i] = 1;
		for(int i = 0 ; i < n-1 ; i++) dp[i][i+1] = a[i] == a[i+1] ? 2:1;			
		for(int i = 2 ; i < n ; i++){
			for(int j = 0 ; j < n-i ; j++){
				if(a[j] == a[j+i])dp[j][j+i] = 2+dp[j+1][j+i-1];
				
				else dp[j][j+i] = max(dp[j+1][j+i],dp[j][j+i-1]);
			}
		}
		cout << dp[0][n-1] << endl;
	}

}		
