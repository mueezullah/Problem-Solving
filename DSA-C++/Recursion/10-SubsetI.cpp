class Solution {
public:
    // TC -> O(2^n) we have 2 choices on each level
    // SC -> O(n)
    void solve(vector<int>& nums, vector<int>& subset, vector<vector<int>>& result, int index){
        if(index >= nums.size()){
            result.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);  // take
        solve(nums, subset, result, index + 1);

        subset.pop_back();      // not_take
        solve(nums, subset, result, index + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;

        solve(nums, subset, result, 0);
        return result;
    }
};