class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count1 = 0, max1 = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                count1++;
                max1 = max(max1, count1);
            }
            else {
                count1 = 0;
            }
        }
        
        return max1;
    }
};