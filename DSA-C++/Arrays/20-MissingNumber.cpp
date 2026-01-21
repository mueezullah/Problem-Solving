class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // APPROACH 1 (2 loops)
        // int sum = 0;
        // int n = nums.size();

        // for(int i = 0; i < n; i++){
        //     sum = sum + i+1;
        // }
        // int arraySum = 0;
        // for(int i = 0; i < n; i++){
        //     arraySum += nums[i];
        // }
        // int ans = sum - arraySum;
        // return ans;

        // APPROACH 2 (1 loop)
        // int n = nums.size();
        // int expectedSum = n * (n + 1) / 2;
        
        // int arraySum = 0;
        // for(int i = 0; i < n; i++){
        //     arraySum += nums[i];
        // }
        // return expectedSum - arraySum;

        // APPROACH 3 (Using XOR operator)
        int n = nums.size();
        int xorr = 0;

        for(int i = 0; i < n; i++){
            xorr = xorr ^ i;
            xorr = xorr ^ nums[i];
        }
        xorr = xorr ^ n;

        return xorr;
    }
};