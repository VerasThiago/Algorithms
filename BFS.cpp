void bfs(int u){
	queue<int> q;
	dist[u] = 0;
	q.push(u);
	vector<bool> visit(N,false);
	visit[u] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 0 ; i < grafo[u].size(); ++i){
			int v = grafo[u][i];
			if(!visit[v]){
				q.push(v);
				dist[v] = dist[u]+1; 
				visit[v] = true;
			}
		}
	}
}
