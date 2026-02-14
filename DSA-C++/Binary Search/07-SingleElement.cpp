class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        int start = 0, end = n - 1;

        while(start <= end){
            int mid = start + (end - start) / 2;
            
            if(mid == 0 && nums[0] != nums[1]) return nums[mid]; // 0-index
            if(mid == n-1 && nums[n-1] != nums[n-2]) return nums[mid]; // last index

            if(nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]){
                return nums[mid];
            }
            
            if((mid % 2 == 0)){
                if(nums[mid] == nums[mid - 1]){ // left 
                    end = mid - 1;
                }
                else { // nums[mid] == nums[mid + 1] // right
                    start = mid + 1;
                }
            }

            else {  // mid % 2 == 1 // odd
                if(nums[mid] == nums[mid - 1]){ // right
                    start = mid + 1;
                }
                else { // nums[mid] == nums[mid + 1] // left
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};