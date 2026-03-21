class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // APPROACH 1 (TLE solution)
        // TC -> O(n^2)
        // vector ans not counted as extra space b/c given in problem statement
        // SC -> O(1) 
        
        // int n = nums.size();
        // vector<int> ans(n, 1);
        // int product = 1;

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){

        //         if(i == j){
        //             continue;
        //         }
        //         product *= nums[j];
        //     }
        //     ans[i] = product;
        //     product = 1;
        // }
        // return ans;

        // APPROACH 2 (Prefix , Suffix)
        // TC -> O(n)
        // SC -> O(n) 
        // int n = nums.size();

        // vector<int> ans(n);
        // vector<int> prefix(n);
        // vector<int> suffix(n);

        // // prefix
        // prefix[0] = 1;
        // for(int i = 1; i < n; i++){
        //     prefix[i] = prefix[i-1] * nums[i-1];
        // }

        // // suffix
        // suffix[n-1] = 1;
        // for(int i = n - 2; i >= 0; i--){
        //     suffix[i] = suffix[i+1] * nums[i+1];
        // }

        // // ans
        // for(int i = 0; i < n; i++){
        //     ans[i] = prefix[i] * suffix[i];
        // }

        // return ans;

        // APPROACH 3 (No Extra space)
        // TC -> O(n)
        // SC -> O(1)

        int n = nums.size();
        vector<int> ans(n);

        ans[0] = 1;
        for(int i = 1; i < n; i++){
            ans[i] = ans[i-1] * nums[i-1];
        }

        int suffix = 1;
        for(int i = n-1; i >= 0; i--){
            ans[i] = ans[i] * suffix;
            suffix *= nums[i];
        }
        return ans;
    }
};