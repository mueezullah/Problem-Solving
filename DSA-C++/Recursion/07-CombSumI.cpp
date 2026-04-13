// class Solution {
// public:
//     // APPROACH 1(At each level every node is called)
//     // TC -> O(N ^ (T/M))
//     // N = numbers of candidates, T = target, M = smallest cadidate
//     // SC -> O(T/M)

//     vector<vector<int>> result;

//     void solve(vector<int>& candidates, int target, int index, vector<int>& comb){
//         if(target == 0){
//             result.push_back(comb);
//             return;
//         }

//         if(target < 0) return;

//         for(int i = index; i < candidates.size(); i++){
//             comb.push_back(candidates[i]);
//             solve(candidates, target - candidates[i], i, comb);
//             comb.pop_back();
//         }
//     }

//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<int> comb;

//         solve(candidates, target, 0, comb);
//         return result;
//     }
// };

class Solution {
public:
    // APPROACH 2(Breaks unwanted calls + Sorted)
    // TC -> O(N log N + N ^ (T/M))
    // SC -> O(T/M)
    
    vector<vector<int>> result;
    void solve(vector<int>& candidates, int target, int index, vector<int>& comb){
        if(target == 0){
            result.push_back(comb);
            return;
        }

        for(int i = index; i < candidates.size(); i++){
            if(candidates[i] > target) break;

            comb.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i, comb);
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> comb;

        solve(candidates, target, 0, comb);
        return result;
    }
};