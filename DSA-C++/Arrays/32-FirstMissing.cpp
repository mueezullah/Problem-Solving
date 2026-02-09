class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // APPROACH 1 (Hashmap)
        // TC -> O(n)
        // SC -> O(n)
        // unordered_map<int, bool> map;
        // // Step 1: Initialize map with false
        // for(int i = 1; i <= n+1; i++){
        //     map[i] = false;
        // }
        // // Step 2: Compare elements with map indices
        // for(int i = 0; i < n; i++){
        //     if(nums[i] >= 1 && nums[i] <= n + 1){
        //         map[nums[i]] = true;
        //     }
        // }
        // // Step 3: Find first index that is still false
        // for(int i = 1; i <= n+1; i++){
        //     if(map[i] == false){
        //         return i;
        //     }
        // }

        // return n + 1;

        // APPROACH 2 (In-place index-hashing)
        // TC -> O(n)
        // SC -> O(1)
        // Place numbers in correct positions
        for(int i = 0; i < n; i++){
            while(nums[i] >= 1 && nums[i] < n && nums[i] != nums[nums[i] - 1]){
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        // Finding first missing positive number
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1){
                return i + 1;
            }
        }
        return n + 1;
    }
};