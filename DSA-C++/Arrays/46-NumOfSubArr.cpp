class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // APPROACH 1 (Prefix + hashmap)
        // TC -> O(n)
        // SC -> O(n)
        // int n = nums.size();
        // unordered_map<int, int> mp;

        // mp[0] = 1;
        // int oddCount = 0;
        // int result = 0;

        // for(int i = 0; i < n; i++){

        //     oddCount += (nums[i] % 2);  // odd numbers have remainder 1
        //     int need = oddCount - k;

        //     if(mp.find(need) != mp.end()){
        //         result += mp[need];

        //     }
        //     mp[oddCount]++;
        // }
        // return result;

        // APPROACH 2 (Sliding Window + Two Pointers)
        // TC -> O(n)
        // SC -> O(1)

        int n = nums.size();

        int oddCount  = 0;
        int prevCount = 0;
        int result    = 0;

        int left  = 0;
        int right = 0;

        while(right < n){
            
            if(nums[right] % 2 == 1){
                oddCount++;
                prevCount = 0;
            }

            while(oddCount == k){
                prevCount++;

                if(nums[left] % 2 == 1){
                    oddCount--;
                }
                left++;
            }

            result += prevCount;
            right++;
        }
        return result;
    }
};
