#include <bits/stdc++.h>

using namespace std;
using ll [[maybe_unused]] = long long;

const int N = 1e3 + 3, M = 2e4 + 4;

int n, m, u, v;

pair<int, int> edgeList[M];
bool adjMatrix[N][N];
vector<int> adjList[N];

void printNeighborsOf(int u) {
    for (int j = 0; j < m; j++) {   // O(m)
        if (edgeList[j].first == u) cout << (edgeList[j].second == u) << " ";
        else if (edgeList[j].second == u)cout << (edgeList[j].first == u) << " ";
    }

    for (int i = 0; i < n; i++) {   // O(n)
        if (adjMatrix[u][i])
            cout << i << " ";
    }

    for (int v : adjList[u]) {  // O(neighbors)
        cout << v << " ";
    }
}

bool areNeighbors(int u, int v) {
    // for (int j = 0; j < m; j++) {
    //     if (edgeList[j].first == u && edgeList[j].first == v || edgeList[j].first == v && edgeList[j].first == u )
    //         return true;
    // }
    // return false;

    // return adjMatrix[u][v] == true;

    for (int y : adjList[u]) {  // O(neighbors)
        if (y == v) return true;
    }
    return false;
}


int main() {

    cin.tie(nullptr)->sync_with_stdio(false);


    cin >> n >> m;
    for (int j = 0; j < m; j++) {
        cin >> u >> v;

        adjMatrix[u][v] = true;
        adjMatrix[v][u] = true;     // undirected

        adjList[u].push_back(v);
        adjList[v].push_back(u);    // undirected

         edgeList[j] = { u, v };

    }
    return 0;
}
// ~ Abd