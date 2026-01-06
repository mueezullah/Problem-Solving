class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        // APPROACH 1 (Brute Force)
        vector<int> ans;

        // for(int i = 0; i < n; i++){
        //     int count = 0;

        //     for(int j = i; j < n; j++){
        //         if(nums[i] == nums[j]){
        //             count++;
        //         }
        //     }
        //     if(count > n/3){
        //         if(ans.empty() || ans[0] != nums[i]){
                    
        //             ans.push_back(nums[i]);
        //             if (ans.size() == 2) break;
        //         }
        //     }
        // }
        // return ans;

        // APPROACH 2 (Hashing)
        // unordered_map<int, int> map;

        // for(int i = 0; i < n; i++){
        //     map[nums[i]]++;

        //     if(map[nums[i]] == (n/3)+1){
        //         ans.push_back(nums[i]);
        //     }
        // }
        // return ans;

        // APPROACH 3 (Moore's Voting Algorithm)
        int count1 = 0, count2 = 0;
        int elem1 = INT_MIN, elem2 = INT_MIN;

        for(int i = 0; i < n; i++){
            if(count1 == 0 && elem2 != nums[i]){
                count1++;
                elem1 = nums[i];
            }
            else if(count2 == 0 && elem1 != nums[i]){
                count2++;
                elem2 = nums[i];
            }

            else if(nums[i] == elem1) count1++;
            else if(nums[i] == elem2) count2++;

            else {
                count1--, count2--;
            }
        }
        // verify moore's algo
        count1 = 0, count2 = 0;
        for(int i = 0; i < n; i++){
            if(elem1 == nums[i]) count1++;
            if(elem2 == nums[i]) count2++;
        }

        if(count1 >= (n/3)+1) ans.push_back(elem1);
        if(count2 >= (n/3)+1) ans.push_back(elem2);
        
        return ans;
    }
};