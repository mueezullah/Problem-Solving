class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;

        // find pivot
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                pivot = i;
                break;
            }
        }
        // if no pivot, reverse entire array
        if(pivot == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // next larger element after finding pivot
        for(int i = n-1; i > pivot; i--){
            if(nums[i] > nums[pivot]){
                swap(nums[i], nums[pivot]);
                break;
            }
        }
        // reverse (pivpt+1 to n-1)
        int k = pivot+1, j = n-1;
        while(k < j){
            swap(nums[k++], nums[j--]);
        }
    }
};