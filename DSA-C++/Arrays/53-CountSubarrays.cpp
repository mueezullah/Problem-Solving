class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        // APPROACH 1
        // TC -> O(n)
        // SC -> O(1)
        long long ans = 0;

        int minkPosition = -1;
        int maxkPosition = -1;
        int badIdx       = -1;

        for(int i = 0; i < nums.size(); i++){

            if(nums[i] < minK || nums[i] > maxK){
                badIdx = i;
            }

            if(nums[i] == minK){
                minkPosition = i;
            }
            if(nums[i] == maxK){
                maxkPosition = i;
            }

            long long smaller = min(minkPosition, maxkPosition);
            long long temp = smaller - badIdx;

            ans += (temp < 0) ? 0 : temp;
        }
        return ans;
    }
};