class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        // APPROACH 1 (Prefix Sum)
        // TC -> O(n)
        // SC -> O(n)
        
        // int n = nums.size();

        // if(k == 0) return nums;

        // vector<int> result(n, -1);

        // if(n < 2*k + 1){
        //     return result;
        // }

        // vector<long long> prefixSum(n, 0);
        // prefixSum[0] = nums[0];

        // for(int i = 1; i < n; i++){
        //     prefixSum[i] = prefixSum[i-1] + nums[i];
        // }

        // for(int i = k; i < n-k; i++){

        //     int left  = i-k;
        //     int right = i+k;

        //     long long sum = prefixSum[right];
        //     if(left > 0){
        //         sum -= prefixSum[left-1];
        //     }

        //     result[i] = sum/(2*k + 1);
        // }
        // return result;


        // APPROACH 2 (Sliding Window + Two Pointers)
        // TC -> O(n)
        // SC -> O(1)

        int n = nums.size();
        int windowSize = 2 * k + 1;

        vector<int> result(n, -1);

        if(windowSize > n) return result;

        long long sum = 0;
        for(int i = 0; i < windowSize; i++){
            sum += nums[i];
        }

        result[k] = sum / windowSize;

        for(int i = k+1; i < n-k; i++){

            sum += nums[i + k];

            sum -= nums[i - k - 1];

            result[i] = sum / windowSize;
        }
        return result;
    }
};