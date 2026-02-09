class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        return {binaryFind(nums, target, true), binaryFind(nums, target, false)};
    }

    int binaryFind(vector<int>& nums, int target, bool find){
        // TC -> O(log n)
        // SC -> O(1)
        int n = nums.size();
        int start = 0, end = n - 1;
        int ans = -1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(nums[mid] < target){
                start = mid + 1;
            }
            else if(nums[mid] > target){
                end = mid - 1;
            }
            else {
                ans = mid;

                if(find){
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
                
            }
        }
        return ans;
    }
};
