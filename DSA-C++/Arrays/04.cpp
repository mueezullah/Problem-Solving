class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // APPROACH 1 (Brute Force) worst solution
        int n = nums.size();

        // for(int i = 0; i < n; i++){
        //     for(int j = i+1; j < n; j++){
        //         if(nums[i] == 0){
        //             swap(nums[i], nums[j]);
        //         }
        //     }
        // }

        // APPROACH 2 (Brute Force) slightly better
        // for(int i = 0; i < n; i++){
        //     if(nums[i] == 0){
        //         for(int j = i+1; j < n; j++){
        //             if(nums[j] != 0){
        //                 swap(nums[i], nums[j]);
        //                 break;
        //             }
        //         }
        //     }
        // }

        // APPROACH 3 (Two Pointer)
        int p = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                swap(nums[i], nums[p]);
                p++;
            }
        }
    }
};