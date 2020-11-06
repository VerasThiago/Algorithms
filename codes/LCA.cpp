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
 
struct Edge {
    int u, v, weight;
    Edge(int uu, int vv, int ww): u(uu), v(vv), weight(ww) {};
};
 
class LCA{
    
public:
    
    int n, logN;
    
    bool builded;
    
    vector< vector< int > > dp;
    vector< vector< pair<int,int> > > graph;
    vector< int > level;
    vector< vector< int >  > maxEdge;
    
    void populateDP(int u, int nodeParent){
        if(~nodeParent) level[u] = level[nodeParent] + 1;
        dp[u][0] = nodeParent;
        maxEdge[u][0] = edgeCost[{u, nodeParent}];
        for(auto v : graph[u]) if(v.first != nodeParent) populateDP(v.first, u);
    }
    
    pair<int,int> walk(int u, int d){
        int ans = 0;
        while(d){
            int jump = (int)log2(d);
            ans = max(ans, maxEdge[u][jump]);
            u = dp[u][jump];
            d -= (1 << jump);
        }
        return {u, ans};
    }
    
    void build(){
        builded = true;
        populateDP(1, -1);
        for(int col = 1; col < logN; col++){
            for(int i = 2; i <= n; i++){
                dp[i][col] = dp[i][col - 1] == -1 ? -1:dp[dp[i][col - 1]][col - 1];
                maxEdge[i][col] = dp[i][col - 1] == -1 ? -1:max(maxEdge[i][col - 1], maxEdge[dp[i][col - 1]][col - 1]);
            }
        }
    }
    
    LCA(int _n){
        n = _n;
        builded = false;
        logN = (int)log2(n * 2);
        level = vector< int >(n * 2, 0);
        graph = vector< vector< pair<int, int> > >(n * 2);
        dp = vector< vector< int > >(n * 2, vector< int >(logN * 2, -1));
        maxEdge =  vector< vector< int > >(n * 2, vector< int >(logN * 2, -1));
    }


    void insert(Edge e){
        graph[e.u].push_back({e.v, e.weight});
        graph[e.v].push_back({e.u, e.weight});
    }
    
    int getLCA(int u, int v){
        if(!builded) build();
        int du = level[u], dv = level[v];
        if(du < dv) return getLCA(v, u);
    
        int diff = du - dv;
        u = walk(u, diff).first;
        
        if(u == v) return u;
    
        for(int i = logN; i >= 0; i--) if(dp[u][i] != -1 and dp[u][i] != dp[v][i]) u = dp[u][i], v = dp[v][i];
        
        return dp[u][0];
    }

    int getMax(int u, int v){
        if(!builded) build();

        int du = level[u], dv = level[v];
        if(du < dv) return getMax(v, u);

        int ans = 0;
        int diff = du - dv;
        tie(u, ans) = walk(u, diff);
        
        if(u == v)  return ans;

        for(int i = logN; i >= 0; i--) 
            if(dp[u][i] != -1 and dp[u][i] != dp[v][i]) 
                ans = max(ans, maxEdge[u][i]), ans = max(ans, maxEdge[v][i]), u = dp[u][i], v = dp[v][i];
            
        return max(ans, max(maxEdge[u][0], maxEdge[v][0]));
    }
    
    int dist(int u, int v){ // Only if edge = 1
        return level[u] + level[v] - 2 * level[getLCA(u, v)];
    }
};
 
void solve(){
    int n;
    scanf("%d", &n);
 
    LCA l(n);
 
    for(int i = 1; i < n; i++){
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        l.insert(Edge(a, b, w));
    }

    auto lca = l.getLCA(a, b);
    auto dist = l.dist(a, b);
    auto maxEdge = l.getMax(a, b);
}