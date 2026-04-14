class Solution {
public:
    // TC -> O(2^n) we have 2 choices on each level
    // SC -> O(n)
    
    void solve(vector<int>& nums, vector<vector<int>>& result, vector<int>& subset, int index){

        if(index >= nums.size()){
            result.push_back(subset);
            return;
        }

        subset.push_back(nums[index]); // take
        solve(nums, result, subset, index + 1);

        subset.pop_back(); // not_take
        int next = index + 1;
        while(next < nums.size() && nums[next] == nums[index]){
            next++;
        }
        solve(nums, result, subset, next); // next == index + 1
        
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> result;
        vector<int> subset;

        sort(nums.begin(), nums.end());

        solve(nums, result, subset, 0);
        return result;
    }
};