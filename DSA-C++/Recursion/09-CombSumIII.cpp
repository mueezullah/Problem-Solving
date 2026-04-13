class Solution {
public:
    vector<vector<int>> result;

    void solve(int k, int n, int index, vector<int>& comb, int sum){
        if(k == comb.size() && n == sum){
            result.push_back(comb);
            return;
        }

        for(int i = index; i <= 9; i++){
            
            if(sum + i > n) break;

            comb.push_back(i);
            solve(k, n, i + 1, comb, sum + i);
            comb.pop_back();
        }  
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> comb;

        solve(k, n, 1, comb, 0);
        return result;
    }
};