class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        int start = 0, end = n - 1;

        while(start < end){
            int mid = start + (end - start) / 2;

            if((mid == 0 || nums[mid] > nums[mid - 1]) && 
                (mid == n-1 || nums[mid] > nums[mid + 1])){
                return mid;
            }

            if(nums[mid] > nums[mid + 1]){
                end = mid;
            }
            else {
                start = mid + 1;
            }
        }
        return -1;
    }
};