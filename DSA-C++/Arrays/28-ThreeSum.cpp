class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            // Skip duplicate fixed elements
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            // If the smallest number is > 0, sum can never be zero
            if(nums[i] > 0){
                break;
            }

            // Two pointers
            int left = i + 1;
            int right = n - 1;

            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];

                if(sum < 0){
                    left++;
                }
                else if(sum > 0){
                    right--;
                }
                else {  // (sum == 0) condition
                    // Valid triplet found
                    ans.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicate values for left pointer
                    while(left < right && nums[left] == nums[left + 1]){
                        left++;
                    }
                    // Skip duplicate values for right pointer
                    while(right > left && nums[right] == nums[right - 1]){
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
        return ans;
    }
};