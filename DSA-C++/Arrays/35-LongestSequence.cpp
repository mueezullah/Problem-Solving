class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // APPROAHCH 1
        // TC -> O(n log n)
        // SC -> O(1)
        // int n = nums.size();
        
        // if(n == 0) return 0;
        // sort(nums.begin(), nums.end());

        // int count = 0, longest = 0;
        // int lastSmaller = INT_MIN;

        // for(int i = 0; i < n; i++){

        //     if(nums[i] - 1 == lastSmaller){
        //         count += 1;
        //     }
        //     else if(nums[i] != lastSmaller){
        //         count = 1;
        //     }

        //     lastSmaller = nums[i];
        //     longest = max(longest, count);
        // }
        // return longest;

        // APPROAHCH 2
        // TC -> O(n)
        // SC -> O(n)

        int n = nums.size();
        if(n == 0) return 0;

        int longest = 0;
        unordered_set<int> st;

        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }

        for(auto it : st){

            if(st.find(it - 1) == st.end()){ // it - 1 doesn't exist
                int count = 1;
                int x = it;

                // while x + 1 exits, keep walking
                while(st.find(x + 1) != st.end()){ // st.count(x + 1)
                    count++;
                    x++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};