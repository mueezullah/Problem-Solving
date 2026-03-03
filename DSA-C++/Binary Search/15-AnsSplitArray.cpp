class Solution {
public:
    // TC -> O(n log(sum))
    // SC -> O(1)
    int countPartitons(vector<int>& nums, int k, int mid){
        long long sum = 0;
        int partition = 1;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(sum + nums[i] <= mid){
                sum += nums[i];
            }
            else {
                sum = nums[i];
                partition++;
            }
        }
        return partition;
    }

    int splitArray(vector<int>& nums, int k) {
        
        int start = *max_element(nums.begin(), nums.end());
        long long end = accumulate(nums.begin(), nums.end(), 0LL);
        int ans = -1;

        while(start <= end){
            int mid = start + (end - start) / 2;
            
            int partition = countPartitons(nums, k, mid);
            if(partition <= k){
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