#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int n , m;
vector<string>grid;
string path;


void backtrack(int row , int col){

    if(row == n - 1 && col == m - 1){
        // TODO: Print the path to cheese bcz we find it *_-.
        cout << path << '\n';
        return ;
    }


    if(col + 1 < m && grid[row][col + 1] != '#'){
        path.push_back('R'); // Do - make a decision
        backtrack(row , col + 1);// Recurse - try your solution
        path.pop_back();// Undo - leave the solution
    }

    if(row + 1 < n && grid[row + 1][col] != '#'){
        path.push_back('D'); //  Do - make a decision
        backtrack(row + 1, col);// Recurse - try your solution
        path.pop_back();// Undo - leave the solution
    }
}

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;
    grid.resize(n);


    for(int i = 0 ; i < n ; i += 1){
        cin >> grid[i];
    }



    backtrack(0 , 0);

}
// ~Abd
