class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n-3; i++){

            // Skip duplicate values for i
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            
            for(int j = i+1; j < n-2; j++){

                // Skip duplicate values for j
                if(j > i+1 && nums[j] == nums[j-1]){
                    continue;
                }

                // Two Pointers
                int left = j + 1;
                int right = n - 1;
                while(left < right){

                    long long sum = (long long)nums[left] + nums[right] + nums[j] + nums[i];

                    if(sum > target){
                        right--;
                    }
                    else if(sum < target){
                        left++;
                    }
                    else {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Skip duplicate values for left pointer
                        while(left < right && nums[left] == nums[left + 1]){
                            left++;
                        }
                        // Skip duplicate values for right pointer
                        while(right > left && nums[right] == nums[right - 1]){
                            right--;
                        }
                        // moving both pointers
                        left++;
                        right--;
                    }
                }
            }   
        }
        return ans;
    }
};