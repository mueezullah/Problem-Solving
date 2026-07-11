class Solution {
public:
    // int sliding(vector<int>& nums, int k){

        // unordered_map<int, int> mp;
        // int n = nums.size();
        // int left = 0, right = 0;
        // int count = 0;

        // while(right < n){

        //     mp[nums[right]]++;

        //     while(mp.size() > k){
                
        //         mp[nums[left]]--;
        //         if(mp[nums[left]] == 0){
        //             mp.erase(nums[left]);
        //         }

        //         left++;
        //     }

        //     count += (right - left + 1);
        //     right++;
        // }
        // return count;
    // }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // APPROACH 1
        // TC -> O(n)
        // SC -> O(n)
        // return sliding(nums, k) - sliding(nums, k-1);


        // APPROACH 2
        // TC -> O(n)
        // SC -> O(n)

        int n = nums.size();
        unordered_map<int, int> mp;
        int left = 0, right = 0;
        int leftMost = 0;
        int result = 0;

        while(right < n){
            mp[nums[right]]++;

            while(mp.size() > k){
                mp[nums[left]]--;

                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }
                left++;
                leftMost = left;
            }

            while(mp[nums[left]] > 1){
                mp[nums[left]]--;
                left++;
            }
            
            if(mp.size() == k){
                result += (left - leftMost + 1);
            }

            right++;
        }
        return result;
    }
};