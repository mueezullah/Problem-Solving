class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        // APPROACH 1 (Brute Force)
        // for(int val : nums){
        //     int count = 0;

        //     for(int elem : nums){
        //         if(elem == val){
        //             count++;
        //         }
        //     }
        //     if(count > n/2) return val;
        // }
        // return -1;

        // APPROACH 2 (Hashing)
        // unordered_map<int, int> map;
        // for(int i = 0; i < n; i++){
        //     map[nums[i]]++;
        // }

        // for(auto i : map){
        //     if (i.second > n/2){
        //         return i.first;
        //     }
        // }
        // return -1;

        // APPROACH 3 (Moore's Voting Algorithm)
        int count = 0, elem = 0;

        for(int i = 0; i < n; i++){
            if(count == 0){
                elem = nums[i];
            }
            else if(nums[i] == elem) {
                count++;
            } else {
                count--;
            }
        }
        // additional step if there is no majoirty element
        int freq = 0;
        for(int i : nums){
            if (i == elem){
                freq++;
            }
        }

        if (freq > n/2) return elem;
        else return -1;
    }
};