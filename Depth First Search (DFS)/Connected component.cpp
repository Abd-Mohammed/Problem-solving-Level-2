#include "bits/stdc++.h"

using namespace std;
using ll [[maybe_unused]] = long long;

const int N = 1e5 + 50;


int n , m;
vector<int>g[N];
vector<bool> vis(N , false);

inline void DFS(int node){

    vis[node] = true;

    for(int child : g[node]){
        if(!vis[child])DFS(child);
    }
}


inline void makeEdge(int u , int v){
    g[u].push_back(v);
    g[v].push_back(u);
}

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;

    for(int u , v , i = 0 ;  i < m ; i += 1){
        cin >> u >> v;
        makeEdge(u  , v);
    }

    int cnt = 0;
    for(int node = 1 ; node <= n ; node += 1){
        if(!vis[node]){
            DFS(node);
            cnt += 1;
        }
    }

    cout << (cnt == 1 ? "YES" : "NO") << '\n';

    return (0 - 0);
}
