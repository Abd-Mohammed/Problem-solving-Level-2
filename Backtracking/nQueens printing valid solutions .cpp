#include "bits/stdc++.h"

using namespace std;

int n , numberOfSol = 0;
vector<vector<char>> board;
vector<bool>ld , rd , rows;


inline void printBoard(){

    // TODO: Printing all valid solution.
    cout << "---------------------------------\n";
    for(int i = 0 ; i < n ; i += 1){
        for(int j = 0 ; j < n ; j += 1){
            cout << board[i][j];
        }
        cout << '\n';
    }
    cout << "---------------------------------\n";
}

inline bool good(int row , int col){
    return (!ld[row - col + n] && !rd[row + col]  && !rows[row]);
}

inline void setValue(int row , int col , bool val , char toChange){
    ld[row - col + n] = rd[row + col] = rows[row] = val;
    board[row][col] = toChange;
}

inline void backtrack(int col){

    // Base case.
    if(col == n){
        numberOfSol += 1;
        printBoard();
        return ;
    }


    for(int row = 0 ; row < n ; row += 1){
        if(good(row , col)){
            setValue(row , col , true , 'Q'); // Do - make a decision
            backtrack(col + 1); // Recurse
            setValue(row , col , false , '.'); // Undo
        }
    }
}


inline void init(){

    ld.assign(n + n + 1 , false);
    rd.resize(n + n + 1 , false);
    rows.resize(n + 1 , false);
    board.assign(n , vector<char>(n , '.'));

}



signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n;
    init();
    backtrack(0);

    cout << "\nThe number of ways: " << numberOfSol << '\n';

    return (0 - 0);
}
// ~Abd