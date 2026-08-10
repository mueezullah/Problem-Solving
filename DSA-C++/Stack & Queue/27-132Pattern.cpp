class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // APPROACH 1 (TLE)
        // TC -> O(n^3)
        // SC -> O(1)

        // int n = nums.size();

        // for(int i = 0; i < n - 2; i++){

        //     for(int j = i+1; j < n - 1; j++){

        //         if(nums[i] < nums[j]){
        //             for(int k = j+1; k < n; k++){
                        
        //                 if(nums[i] < nums[k] && nums[k] < nums[j]){
        //                     return true;
        //                 }
        //             }
        //         }
        //     }
        // }

        // return false;

        // APPROACH 2 (TLE)
        // TC -> O(n^2)
        // SC -> O(1)

        // int n = nums.size();
        // int mini = INT_MAX;

        // for(int i = 0; i < n-1; i++){
            
        //     mini = min(mini, nums[i]);
        //     for(int j = i+1; j < n; j++){

        //         if(mini < nums[j] && nums[j] < nums[i]){
        //             return true;
        //         }
        //     }
        // }
        // return false;

        // APPROACH 3 (Optimal)
        // TC -> O(n)
        // SC -> O(n)


        int n = nums.size();
        int nums3 = INT_MIN;
        stack<int> st;

        for(int i = n-1; i >= 0; i--){

            if(nums[i] < nums3){
                return true;
            }

            while(!st.empty() && st.top() < nums[i]){
                nums3 = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};