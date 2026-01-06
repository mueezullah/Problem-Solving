class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int j = 2;

        if(n <= 2) return n;
        
        for(int i = 2; i < n; i++){
            // compare with j-2 because we allow only 2 copies
            if (nums[i] != nums[j-2]){
                nums[j] = nums[i];
                j++;
            }
           
        }
        return j;
    }
};