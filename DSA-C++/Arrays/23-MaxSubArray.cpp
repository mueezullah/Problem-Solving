class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // APPROACH 1 (Brute force) TLE on Leetcode
        // int n = nums.size();
        // int maxSum = INT_MIN;

        // for(int i = 0; i < n; i++){
        //     int currSum = 0;

        //     for(int j = i; j < n; j++){
        //         currSum += nums[j];
        //         maxSum = max(currSum, maxSum);
        //     }
        // }
        // return maxSum;

        // APPROACH 2 (Kadane's Algorithm)
        int currSum = 0;
        int maxSum = INT_MIN;

        for(int i = 0; i < nums.size(); i++){
            currSum += nums[i];
            maxSum = max(maxSum, currSum);

            if(currSum < 0){
                currSum = 0;
            }
        }
        return maxSum;
    }
};