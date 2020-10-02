#include < bits/stdc++.h >
#define ii pair< int,int >
#define ff first
#define ss second
#define pb push_back
#define vi vector< int >
#define ll long long    
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define vll vector< long long >
#define inf (int) 2e9
#define infll (long long) 2e18
#define endl '\n'

using namespace std;
 
vector< int > subTreeSize;
 
int buildSize(int u, vector< bool > &visited, vector< vector < int > > &graph){
    visited[u] = true;
    for(auto v : graph[u]) if(!visited[v]) subTreeSize[u] += buildSize(v, visited, graph);
    return subTreeSize[u];
}
 
 
class LCA{
 
public:
 
    int n, logN;
    
    bool builded;
 
    vector< vector< int > > dp;
    vector< vector< int > > graph;
    vector< bool > visited;
    vector< int > level;
 
    void populateDP(int u, int parent){
        if(~parent) level[u] = level[parent] + 1;
        visited[u] = true;
        dp[u][0] = parent;
        for(auto v : graph[u]) if(!visited[v]) populateDP(v, u);
        
    }
 
    int walk(int u, int d){
        while(d){
            int jump = (int)log2(d);
            u = dp[u][jump];
            d -= (1 << jump);
        }
        return u;
    }
 
    void build(){
        builded = true;
        for(int i = 1; i <= n; i++) visited[i] = false;
        populateDP(1, -1);
        for(int col = 1; col < logN; col++)
            for(int i = 2; i <= n; i++)
                dp[i][col] = dp[i][col - 1] == -1 ? -1:dp[dp[i][col - 1]][col - 1];
    }
 
    LCA(int _n){
        n = _n;
        builded = false;
        logN = (int)log2(n * 2);
        level = vector< int >(n * 2, 0);
        graph = vector< vector< int > >(n * 2);
        visited = vector< bool >(n * 2, false);
        dp = vector< vector< int > >(n * 2, vector< int >(logN * 2, -1));
    }
 
 
    void insert(int x, int y){
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
 
    int getLCA(int u, int v){
        if(!builded) build();
        int du = level[u], dv = level[v];
        if(du < dv) return getLCA(v, u);
 
        int diff = du - dv;
        u = walk(u, diff);
        
        if(u == v) return u;
 
        for(int i = logN; i >= 0; i--){
            if(dp[u][i] != -1 and dp[u][i] != dp[v][i]) u = dp[u][i], v = dp[v][i];
        }
        return dp[u][0];
    }
 
    int dist(int u, int v){
        return level[u] + level[v] - 2 * level[getLCA(u, v)];
    }
};
 
void solve(){
    int n;
    scanf("%d", &n);
 
    subTreeSize = vector<int>(2 * n, 1);
    
    LCA l(n);
 
    for(int i = 1; i < n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        // build graph
        l.insert(x,y); 
    }

    // Populate subtree size
    buildSize(1, l.visited, l.graph);
    auto lca = l.getLCA(a, b);
    auto dist = l.dist(a, b)
}