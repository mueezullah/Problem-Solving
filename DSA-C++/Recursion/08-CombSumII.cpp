class Solution {
public:
    // TC -> O(2^n*k)
    // n = candidates, k = combination length
    // Sorting O(n log n) — done once
    // backtrack O(2^n) worst case
    // Copying each result O(k) per combination found

    // SC -> O(n)
    // n = deepest level of recursion stack, n = comb vector

    vector<vector<int>> result;

    void solve(vector<int>& candidates, int target, int index, vector<int>& comb){

        if(target == 0){
            result.push_back(comb);
            return;
        }

        for(int i = index; i < candidates.size(); i++){
            
            if(candidates[i] > target) break;

            if(i > index && candidates[i] == candidates[i-1]){
                continue;
            }

            comb.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i + 1, comb);
            comb.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> comb;

        sort(candidates.begin(), candidates.end());

        solve(candidates, target, 0, comb);
        return result;
    }
};