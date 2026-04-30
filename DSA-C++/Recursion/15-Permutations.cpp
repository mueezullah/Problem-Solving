class Solution {
public:
    // void solve2(vector<int>& nums, vector<vector<int>>& result, int index){
    //     if(index == nums.size()){
    //         result.push_back(nums);
    //         return;
    //     }

    //     for(int i = index; i < nums.size(); i++){
    //         swap(nums[index], nums[i]);
    //         solve2(nums, result, index + 1);
    //         swap(nums[index], nums[i]);
    //     }
    // }

    void solve1(vector<int>& nums, vector<vector<int>>& result, vector<int>& temp,
                unordered_set<int>& st){
            
            if(temp.size() == nums.size()){
                result.push_back(temp);
                return;
            }

            for(int i = 0; i < nums.size(); i++){

                if(st.find(nums[i]) == st.end()){

                    temp.push_back(nums[i]);
                    st.insert(nums[i]);

                    solve1(nums, result, temp, st);

                    temp.pop_back();
                    st.erase(nums[i]);
                }
            }
        }

    vector<vector<int>> permute(vector<int>& nums) {
        // APPROACH 1
        // TC -> O(n! * n)
        // SC -> O(n)

        vector<vector<int>> result;
        vector<int> temp;
        unordered_set<int> st;

        solve1(nums, result, temp, st);
        return result;

        // APPROACH 2
        // TC -> O(n! * n)
        // SC -> O(n)
        // vector<vector<int>> result;

        // solve2(nums, result, 0);
        // return result;
    }
};