/* Question Link: https://leetcode.com/problems/subsets/description/ */

class Solution {
public:
    vector<vector<int>> ans;
    void gen(const vector<int> & nums , int idx , vector<int> subsets){

        if(idx == (int)nums.size()){
            ans.push_back(subsets);
            return;
        }

        subsets.push_back(nums[idx]);  // do
        gen(nums, idx + 1 , subsets); // recurse
        subsets.pop_back();// undo


        gen(nums, idx + 1 , subsets); // move to next element. 
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        gen(nums , 0 , {});

        return ans;
    }
};
