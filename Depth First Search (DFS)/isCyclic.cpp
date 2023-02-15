#include "bits/stdc++.h"

using namespace std;
using ll [[maybe_unused]] = long long;

const int N = 1e5 + 50;


int n , m;
vector<int>g[N];
vector<bool> vis(N , false);

inline bool isCyclic(int node , int par){
    vis[node] = true;
    for (int child : g[node]) {
        if (vis[child] && child != par)   return true;
        if (!vis[child]) {
            if (isCyclic(child, node)) return true;
        }
    }
    return false;
}


inline void makeEdge(int u , int v){
    g[u].push_back(v);
    g[v].push_back(u);
}

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;

    int st ;
    for(int u , v , i = 0 ;  i < m ; i += 1){
        cin >> u >> v;
        makeEdge(u, v);
        st = u;
    }

    bool good = isCyclic(st , -1);
    cout << (good ? "YES" : "NO") << '\n';


    return (0 - 0);
}
