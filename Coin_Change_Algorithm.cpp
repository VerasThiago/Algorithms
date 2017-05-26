int coin(int troco, vector<int> moedas){
	vector<int> ans(troco+1,1e9+7);
	ans[0] = 0;
	for(int i = 1 ; i <= troco; i++){
		for(int j = 0 ; j < moedas.size(); j++){
			if(i < moedas[j]) break;
			ans[i] = min(ans[i],1+ans[i - moedas[j]]);
		}
	}
	return ans[troco];
}
