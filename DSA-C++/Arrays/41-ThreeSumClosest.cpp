class Solution {
public:
    // APPRAOCH 1
    // TC -> O(n^3)
    // SC -> O(1)
    int threeSumClosest(vector<int>& nums, int target) {
    //     int n = nums.size();

    //     int closestSum = nums[0] + nums[1] + nums[2];

    //     for(int i = 0; i < n - 2; i++){
    //         for(int j = i + 1; j < n - 1; j++){
    //             for(int k = j + 1; k < n; k++){

    //                 int currSum = nums[i] + nums[j] + nums[k];

    //                 if(abs(currSum - target) < abs(closestSum - target)){
    //                     closestSum = currSum;
    //                 }

    //                 if(closestSum == target){
    //                     return closestSum;
    //                 }
    //             }
    //         }
    //     }
    //     return closestSum;

        // APPRAOCH 2 (Two Pointer)
        // TC -> O(n^2)
        // SC -> O(1)

        int n = nums.size();
        sort(nums.begin(), nums.end());

        int closestSum = nums[0] + nums[1] + nums[2];

        for(int k = 0; k < n - 2; k++){

            int left  = k + 1;
            int right = n - 1;

            while(left < right){

                int currSum = nums[k] + nums[left] + nums[right];

                if(abs(currSum - target) < abs(closestSum - target)){
                    closestSum = currSum;
                }
                if(closestSum == target) return closestSum;

                if(currSum < target){
                    left++;
                } else {
                    right--;
                }

            }
        }
        

        return closestSum;
    }
};
