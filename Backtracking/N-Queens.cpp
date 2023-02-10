/* Question Link: https://leetcode.com/problems/n-queens/ */

class Solution {
public:

    vector<vector<string>>ans;
    int N ;
    vector<bool>ld, rd , rows;

    bool good(int row , int col){
        return ld[row - col + N] == false &&
               rd[row + col] == false &&
               rows[row] == false;

    }
    void gen(int col , vector<string> & board){
        if(col == N){
            ans.push_back(board);
            return ;
        }

        for(int row = 0; row < N ; row += 1){
            if(good(row , col)){
                // do
                board[row][col] = 'Q';
                ld[row - col + N] = true , rd[row + col ] = true, rows[row] = true;
                // recurse
                gen(col + 1 , board);
                // undo
                ld[row - col + N] = false , rd[row + col ] = false, rows[row] = false;
                board[row][col] = '.';
            }
        }

    }



    vector<vector<string>> solveNQueens(int n) {
        N = n;
        ld.resize(n + n + 1);
        rd.resize(n + n + 1);
        rows.resize(n + 1);

        vector<string>board(n,string(n , '.'));

        gen(0,board);

        return ans;

    }
};
