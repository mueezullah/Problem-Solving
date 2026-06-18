class Solution {
public:
    // APPRAOCH 1 (TLE)
    // TC -> O(N^2)
    // SC -> o(1)
    int numSubarraysWithSum(vector<int>& nums, int goal) {
    //     int n = nums.size();
    //     int ans = 0;

    //     for(int i = 0; i < n; i++){

    //         int sum = 0;
    //         for(int j = i; j < n; j++){
    //             sum += nums[j];

    //             if(sum == goal){
    //                 ans++;
    //             }

    //             if(sum > goal){
    //                 break;
    //             }
    //         }
    //     }
    //     return ans;

        // APPROACH 2 (Prefix + Hashing)
        // TC -> O(n)
        // SC -> O(n)

        // int n = nums.size();
        // int ans = 0;

        // unordered_map<int, int> prefixCount;
        // prefixCount[0] = 1;

        // int currSum = 0;

        // for(int i = 0; i < n; i++){

        //     currSum += nums[i];
        //     int remainingSum = currSum - goal;

        //     if(prefixCount.find(remainingSum) != prefixCount.end()){
                
        //         ans += prefixCount[remainingSum];
        //     }
        //     prefixCount[currSum]++;
        // }
        // return ans;

        // APPROACH 3 (Sliding window + Two Poitners)
        // TC -> O(n)
        // SC -> O(1)

        int n = nums.size();

        int left  = 0;
        int right = 0;

        int windowSum = 0;
        int countZeros = 0;
        int result = 0;

        while(right < n){

            windowSum += nums[right];

            while((left < right) && (nums[left] == 0 || windowSum > goal)){

                if(nums[left] == 0){
                    countZeros++;
                } else {
                    countZeros = 0;
                }

                windowSum -= nums[left];
                left++;
            }

            if(windowSum == goal){
                result += 1 + countZeros;
            }
            right++;
        }

        return result;
    }
};