class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // APPROACH 1 (TLE solution)
        // TC -> O(n^2)
        // SC -> O(1)

        // int maxLen = INT_MIN;
        // int n = nums.size();

        // for(int i = 0; i < n; i++){
            
        //     int count = 0;
        //     int flipLeft = k;

        //     for(int j = i; j < n; j++){
                
        //         if(nums[j] == 1){
        //             count++;
        //         }
                
        //         else{  //(nums[j] == 0)
        //             if(flipLeft > 0){
        //                 flipLeft--;
        //                 count++;
        //             }
        //             else {
        //                 break;
        //             }
        //         }
        //     }
        //     maxLen = max(maxLen, count);
        // }
        // return maxLen;

        // APPROACH 2 (Sliding window + Two Pointers)
        // TC -> O(n) + O(n) -> (2n)
        // SC -> O(1)

        // int maxLen = 0;
        // int kCount = 0;
        // int left = 0;
        // int right = 0;
        // int n = nums.size();

        // while(right < n){
            
        //     if(nums[right] == 0){
        //         kCount++;
        //     }

        //     while(kCount > k){
        //         if(nums[left] == 0){
        //             kCount--;
        //         }

        //         left++;
        //     }
        //     if(kCount <= k){
        //         maxLen = max(maxLen, right - left + 1);
        //     }
        //     right++;
        // }
        // return maxLen;


        // APPROACH 3 (Sliding window + Two Pointers)
        // TC -> O(n)
        // SC -> O(1)

        int left = 0;
        int n = nums.size();
        int right = 0;
        int maxLen = 0;
        int zeroCount = 0;

        while(right < n){
            if(nums[right] == 0){
                zeroCount++;
            }

            if(zeroCount > k){
                if(nums[left] == 0){
                    zeroCount--;
                }
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);  
            right++;
        }
        return maxLen;
    }
};