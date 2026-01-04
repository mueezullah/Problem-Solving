class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        // APPROACH 1 (Brute Force)
        // for(int i = 0; i < n; i++){
        //     for(int j = i+1; j < n; j++){
        //         if(nums[i] > nums[j]){
        //             swap(nums[i], nums[j]);
        //         }
        //     }
        // }

        // APPROACH 2 (Sorting)
        // sort(nums.begin(), nums.end());

        // APPROACH 3 (Counting) 2 passes
        // int count0 = 0, count1 = 0, count2 = 0;

        // for(int i = 0; i < n; i++){
        //     if(nums[i] == 0) count0++;
        //     else if(nums[i] == 1) count1++;
        //     else count2++;
        // }

        // int index = 0;
        // for(int i = 0; i < count0; i++){
        //     nums[index] = 0;
        //     index++;
        // }
        // for(int i = 0; i < count1; i++){
        //     nums[index] = 1;
        //     index++;
        // }
        // for(int i = 0; i < count2; i++){
        //     nums[index] = 2;
        //     index++;
        // }

        // APPROACH 4 (Dutch National Flag Algorithm) 1 pass 
        int low = 0, high = n-1, mid = 0;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};