class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        // APPROACH 1 (Extra Arrays)
        // vector<int> ans, neg, pos;

        // for(int i : nums){
        //     if(i > 0){
        //         pos.push_back(i);
        //     }
        //     else if(i < 0){
        //         neg.push_back(i);
        //     }
        // }
        // for(int i = 0; i < (n/2); i++){
        //     ans.push_back(pos[i]);
        //     ans.push_back(neg[i]);

        // }
        // return ans;

        // APPROACH 2 (Single extra space)
        vector<int> ans(n, 0);
        int posIdx = 0, negIdx = 1;

        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                ans[posIdx] = nums[i];
                posIdx += 2;
            }
            else if(nums[i] < 0){
                ans[negIdx] = nums[i];
                negIdx += 2;
            }
        }
        return ans;
    }
};