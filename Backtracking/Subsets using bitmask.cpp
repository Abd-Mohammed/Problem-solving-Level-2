/* Question Link: https://leetcode.com/problems/subsets/description/ */

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        int n = (int)nums.size();
        int noOfSubset = 1 << n;

        vector<vector<int>> ans;

        for(int mask = 0 ; mask < noOfSubset ; mask += 1){
            vector<int> cur;
            for(int j = 0 ; j < n ; j += 1){
                if(mask >> j & 1){
                    cur.push_back(nums[j]);
                }
            }

            ans.push_back(cur);
        }

        return ans;
    }
};