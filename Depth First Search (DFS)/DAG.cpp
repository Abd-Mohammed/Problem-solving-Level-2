#include "bits/stdc++.h"

using namespace std;
using ll [[maybe_unused]] = long long;

const int N = 1e5 + 50;
const int NV = 0 , IP = 1 , VI = 2;

int n , m;
vector<int>g[N];
vector<bool> status(N);

inline bool DAG(int node){

    status[node] = IP;

    for(int child : g[node]){
        if(status[child] == IP)return true;
        if(status[child] == NV)if(DAG(child))return true;
    }

    status[node] = VI;
    return false;
}


inline void makeEdge(int u , int v){
    g[u].push_back(v); // u --> v
}

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;

    for(int u , v , i = 0 ;  i < m ; i += 1){
        cin >> u >> v;
        makeEdge(u , v);
    }

    for(int node = 1 ;  node <= n ; node += 1){
        if(status[node] == NV){
            if(DAG(node)){
                return void(cout << "YES"), 0;
            }
        }
    }
    cout << "NO";
    return (0 - 0);
}
