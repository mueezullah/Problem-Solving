class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // APPROACH 1 (HashMap)
        // TC -> O(n)
        // SC -> O(n)

        // int n = nums.size();
        // unordered_map<int, int> mp;

        // for(int i = 0; i < n; i++){

        //     if(mp.find(nums[i]) != mp.end()){
                
        //         if(i - mp[nums[i]] <= k){
        //             return true;
        //         }
        //     } 
            
        //     mp[nums[i]] = i;  // {number, index}
            
        // }
        // return false;

        // APPROACH 2 (Sliding window)
        // TC -> O(n)
        // SC -> O(k) size of window

        int n = nums.size();
        unordered_set<int> window;

        for(int i = 0; i < n; i++){
            
            if(window.find(nums[i]) != window.end()){
                return true;
            }

            window.insert(nums[i]);

            if(window.size() > k){
                window.erase(nums[i-k]);
            }
            
        }
        return false;
    }
};