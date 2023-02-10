/* Question Link: https://leetcode.com/problems/generate-parentheses/ */

class Solution {
public:
    vector<string>ans;
    void gen(int o , int c, int &n , string toBuild){

        if((int)toBuild.size() == 2 * n){
            ans.push_back(toBuild);
            return;
        }
        if(o < n){
            toBuild += '(';
            gen(o + 1 , c, n , toBuild);
            toBuild.pop_back();
        }

        if(c < o){
            toBuild += ')';
            gen(o , c + 1, n , toBuild);
            toBuild.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        gen(0 , 0,n,"");

        return ans;
    }
};
