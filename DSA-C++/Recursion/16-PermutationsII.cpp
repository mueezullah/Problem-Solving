class Solution {
public:
    // void solve1(vector<int>& nums, int n, vector<vector<int>>& result,
    //            vector<int>& temp, unordered_map<int, int>& map){
        
    //     if(temp.size() == n){
    //         result.push_back(temp);
    //         return;
    //     }

    //     for(auto [num, count] : map){
    //         if(count == 0) continue;

    //         temp.push_back(num);
    //         map[num]--;

    //         solve1(nums, n, result, temp, map);

    //         temp.pop_back();
    //         map[num]++;
    //     }
    // }

    // void solve2(vector<int>& nums, vector<vector<int>>& result, int index){
        
    //     if(index == nums.size()){
    //         result.push_back(nums);
    //         return;
    //     }

    //     unordered_set<int> st;
        
    //     for(int i = index; i < nums.size(); i++){

    //         if(st.find(nums[i]) != st.end()){
    //             continue;
    //         }

    //         st.insert(nums[i]);
    //         swap(nums[i], nums[index]);

    //         solve2(nums, result, index + 1);

    //         swap(nums[i], nums[index]);
    //     }
    // }

    void solve3(vector<int>& nums, vector<vector<int>>& result,
                vector<int>& temp, vector<bool>& used){
        
        if(temp.size() == nums.size()){
            result.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++){

            if(used[i] == true){
                continue;
            }

            if(i > 0 && nums[i] == nums[i-1] && !used[i-1]){
                continue;
            }

            temp.push_back(nums[i]);
            used[i] = true;

            solve3(nums, result, temp, used);

            temp.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // APPROACH 1 ()
        // TC -> O(n! * n)
        // SC -> O(n)

        // vector<vector<int>> result;
        // vector<int> temp;

        // unordered_map<int, int> map;

        // int n = nums.size();

        // for(int num : nums){
        //     map[num]++;
        // }
        // solve1(nums, n, result, temp, map);
        // return result;



        // APPROACH 2
        // TC -> O(n! * n)
        // SC -> O(n^2)

        // vector<vector<int>> result;

        // solve2(nums, result, 0);
        // return result;

        // APPROACH 3
        // TC -> O(n! * n)
        // SC -> O(n)

        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> used(nums.size(), false);

        solve3(nums, result, temp, used);
        return result;
    }
};