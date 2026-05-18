class Solution {
public:

    // void solve(vector<int>& nums, vector<vector<int>>& subsets,
    //             vector<int>& currSubset, int idx){
        
    //     if(idx == nums.size()){
    //         subsets.push_back(currSubset);
    //         return;
    //     }

    //     currSubset.push_back(nums[idx]);
    //     solve(nums, subsets, currSubset, idx + 1);
    //     currSubset.pop_back();

    //     solve(nums, subsets, currSubset, idx + 1);
    // }


    // int solveTwo(vector<int>& nums, int idx, int Xor){

    //     if(idx == nums.size()){
    //         return Xor;
    //     }

    //     int include = solveTwo(nums, idx+1, nums[idx] ^ Xor);
    //     int exclude = solveTwo(nums, idx+1, Xor);

    //     return include + exclude;
    // }

    int subsetXORSum(vector<int>& nums) {
        // APPROACH 1
        // TC -> O(2^n * N) : N is the length of the subset
        // SC -> O(2^n * N)
        // vector<vector<int>> subsets;
        // vector<int> currSubset;

        // solve(nums, subsets, currSubset, 0);

        // int result = 0;

        // for(vector<int>& subset : subsets){
        //     int Xor = 0;
        //     for(int &num : subset){
        //         Xor ^= num;
        //     }
        //     result += Xor;
        // }
        // return result;


        // APPROACH 2
        // TC -> O(2^n)
        // SC -> O(n)

        // return solveTwo(nums, 0, 0);


        // APPROACH 3
        // TC -> O(n)
        // SC -> O(1)

        int n = nums.size();

        int result = 0;

        for(int &num : nums){
            result |= num;
        }
        return result << (n-1);
    }
};