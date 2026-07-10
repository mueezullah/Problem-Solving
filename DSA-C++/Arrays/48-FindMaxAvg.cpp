class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // APPROACH 1 (TLE)
        // TC -> O(n*k)
        // SC -> O(1)

        // int n = nums.size();
        // double maxAvg = INT_MIN;

        // for(int i = 0; i <= n-k; i++){ // n-k+1 times
            
        //     double sum = 0;
        //     for(int j = i; j < i+k; j++){ // k times
        //         sum += nums[j];
        //     }
            
        //     double average = sum / k;
        //     maxAvg = max(maxAvg, average);
        // }
        // return maxAvg;

        // APPROACH 2 (Sliding Window)
        // TC -> O(n)
        // SC -> O(1)

        int n = nums.size();
        double sum = 0;

        for(int i = 0; i < k; i++){
            sum += nums[i];
        }

        int left = 0;
        int right = k;
        double maxAvg = sum / k;

        while(right < n){
            sum -= nums[left];
            sum += nums[right];
            left++;
            right++;

            maxAvg = max(maxAvg, sum / k);
        }

        return maxAvg;
    }
};