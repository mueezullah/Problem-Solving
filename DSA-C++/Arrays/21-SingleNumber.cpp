class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        // APPROACH 1 (Hashing)
        // unordered_set<int> seen;

        // for(int i : nums){
            
        //     if(seen.count(i)){
        //         seen.erase(i);
        //     } else {
        //         seen.insert(i);
        //     }
        // }
       
        // return *seen.begin();

        // APPROACH 2 (XOR)
        int xorr = 0;
        for(int i = 0; i < n; i++){
            xorr = xorr ^ nums[i];
        }
        return xorr;
    }
};