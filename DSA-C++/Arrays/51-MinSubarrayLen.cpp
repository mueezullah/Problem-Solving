class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // APPROACH 1
        // TC -> o(N^2)
        // SC -> O(1)
        // int n = nums.size();
        // int minLen = INT_MAX;

        // for(int i = 0; i < n; i++){

        //     int sum = 0;
        //     for(int j = i; j < n; j++){
        //         sum += nums[j];

        //         if(sum >= target){
        //             int len = j - i + 1;
        //             minLen = min(minLen, len);
        //             break;
        //         }
        //     }
        // }

        // return (minLen == INT_MAX) ? 0 : minLen;

        // APPROACH 2 (Sliding WIndow)
        // TC -> o(N)
        // SC -> O(1)
        
        int n = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        int minLen = INT_MAX;

        while(right < n){
            
            sum += nums[right];
            
            while(sum >= target){
                int window = right - left + 1;
                minLen = min(minLen, window);

                sum -= nums[left];
                left++;
            }

            right++;
        }

        return (minLen == INT_MAX) ? 0 : minLen;
    }
};