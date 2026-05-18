class Solution {
public:
    // TC -> O(4^N)
    // SC -> O(N)
    bool solve(vector<int>& matchsticks, int target, vector<int>& sides, int idx){

        if(idx == matchsticks.size()){
            
            return sides[0] == sides[1] && 
                   sides[1] == sides[2] && 
                   sides[2] == sides[3];
        }

        for(int i = 0; i < 4; i++){

            if(sides[i] + matchsticks[idx] > target){
                continue;
            }
            if(i > 0 && sides[i] == sides[i-1]){
                continue;
            }
            
            sides[i] += matchsticks[idx];
            if(solve(matchsticks, target, sides, idx+1)){
                return true;
            }
            sides[i] -= matchsticks[idx];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        
        if(matchsticks.size() == 0){
            return false;
        }
        int sum = 0;
        for(int i = 0; i < matchsticks.size(); i++){
            sum += matchsticks[i];
        }
        if(sum % 4 != 0) return false;
        
        int target = sum / 4;

        vector<int> sides(4, 0);
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());

        if(matchsticks[0] > target) return false;

        return solve(matchsticks, target, sides, 0);
    }
};