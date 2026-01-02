class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // APPROACH 1 (Nested Loops)
        // for(int i = 0; i < nums.size()-1; i++){
        //     for(int j = i+1; j < nums.size(); j++){
        //         if(nums[i] == nums[j]) return true;
        //     }
        // }
        // return false;

        // APPROACH 2 (Sort + Scan)
        // sort(nums.begin(), nums.end());
        // for(int i = 1; i < nums.size(); i++){
        //     if(nums[i] == nums[i-1]){
        //         return true;
        //     }
        // }
        // return false;

        // APPROACH 3 (Hash Set) optimized
        unordered_set<int> seen;
        for(int i : nums){
            if(seen.count(i) > 0){
                return true;
            }
            seen.insert(i);
        }
        return false;
    }
};