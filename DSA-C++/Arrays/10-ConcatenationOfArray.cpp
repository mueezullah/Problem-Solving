class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        // APPROACH 1 (Using extra space)
        // vector<int> ans(n*2);

        // for(int i = 0; i < n; i++){
        //     ans[i] = nums[i];
        //     ans[n+i] = nums[i];
        // }
        // return ans;
        
        // APPRAOCH 2 (Without using extra space)
        for(int i = 0; i < n; i++){
            nums.push_back(nums[i]);
        }
        return nums;
    }
};