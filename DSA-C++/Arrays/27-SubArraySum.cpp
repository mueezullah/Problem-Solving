class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // APPROACH 1 (Brute Force)
        int n = nums.size();
        int ans = 0;

        // for(int i = 0; i < n; i++){
        //     int sum = 0;
        //     for(int j = i; j < n; j++){
        //         sum += nums[j];
        //         if(sum == k){
        //             ans++;
        //         }
        //     }
        // }
        // return ans;

        // APPROACH 2 (Prefix + Hashing)
        unordered_map<int, int> prefixSumCount; // stroing the frequency of prefix sums
        prefixSumCount[0] = 1; // base case: prefix sum of 0 occurs once (imp for subarrays starting at 0-index)

        int currSum = 0;

        for(int i = 0; i < n; i++){
            currSum += nums[i];

            int val = currSum - k;
            if(prefixSumCount.find(val) != prefixSumCount.end()){  // Check if that prefix sum exists in our map

                // If yes, add its frequency to ans
                // Each occurrence represents a valid subarray ending at current index
                ans += prefixSumCount[val];
            }

            // Record current prefix sum in the map
            // If it already exists, increase frequency by 1
            prefixSumCount[currSum]++;
        }

        return ans;
    }
};