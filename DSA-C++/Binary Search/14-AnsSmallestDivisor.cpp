class Solution {
public:
    int sumByDivisor(vector<int>& nums, int div, int n){
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += ceil((double)nums[i]/(double)div);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int start = 1, end = *max_element(nums.begin(), nums.end());
        int ans = -1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(sumByDivisor(nums, mid, n) <= threshold){
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return ans;
    }
};