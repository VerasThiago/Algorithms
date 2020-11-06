#include <bits/stdc++.h>

#define N 200005
using namespace std;

struct Edge {
    int u, v, weight;
    Edge(int uu, int vv, int ww): u(uu), v(vv), weight(ww) {};
};

int p[N];
int s[N];

int find(int a) {
    if (p[a] == a) return a;
    return p[a] = find(p[a]);
}
 
void join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (s[a] < s[b]) swap(a, b);
        p[b] = a;
        s[a] += s[b];
    }
}

vector<Edge> mst(vector<Edge> edges, int n){

    vector<Edge> result;
    n++, cost = 0;

    for(int i = 0; i < N; i++)p[i] = i, s[i] = 1;

    sort(edges.begin(), edges.end(), [](const Edge &A, const Edge &B  ){
        return A.weight < B.weight;
    });

    for (Edge e : edges) {
        if (find(e.u) != find(e.v)) {
            cost += e.weight;
            result.push_back(e);
            table[{e.u, e.v}] = true;
            join(e.u, e.v);
        }
    }
    
    return result;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<Edge> edges;

    for(int i = 0; i < m; i++){
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        edges.push_back(Edge(a, b, w));
    }

    vector<Edge> result = mst(edges, n);
}