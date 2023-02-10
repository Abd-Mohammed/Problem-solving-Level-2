/* Question Link: https://www.codechef.com/problems/NICARRAY?tab=statement */

#include "bits/stdc++.h"

using namespace std;
using ll = long long;
#define mod(a) (a % MOD)

const int MOD = 1e9 + 7 ;


int n , s , sum , ans = 0;
vector<int>toReplace , sub;


void init(){
    toReplace.clear();
    sub.clear();
    sum = ans = 0;
}

void calc(int idx){

    if(sum > s || n < (int)sub.size()){
        return ;
    }

    if(idx >= (int)toReplace.size()){
        if(sum == s && (int)sub.size() == n){
            for(int i = 0 ; i < n ; i += 1){
                for(int j = i + 1;  j <  n ; j+= 1){
                    ans = mod(ans + __gcd(sub[i] , sub[j]));
                }
            }
        }
        return ;
    }

    for(int i = 1 ; i <= 18 ; i += 1){
        // do
        sub.push_back(i);
        sum += i;
        // recurse
        calc(idx + 1);
        // undo
        sub.pop_back();
        sum -= i;
    }
}


inline void test_case(){

    cin >> n >> s;
    for(int x , i = 0 ; i < n ; i+= 1){
        cin >> x;
        if(x == -1){
            toReplace.push_back(x);
        }else{
            sum += x;
            sub.push_back(x);
        }
    }

    calc(0);
    cout << mod(ans) << '\n';
    init();

}


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        test_case();
    }
}
//~Abd
