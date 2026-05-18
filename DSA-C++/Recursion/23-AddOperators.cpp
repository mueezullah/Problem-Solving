class Solution {
public:
    // APPROACH 1
    // TC -> O(4^N * N)
    // SC -> O(4^N * N)
    // void solve(string& num, int target, vector<string>& result, long temp, long prevNum, int idx, string s){
        
    //     if(idx == num.length()){
    //         if(temp == target){
    //             result.push_back(s);
    //         }
    //         return;
    //     }

    //     for(int i = idx; i < num.length(); i++){

    //         // leading 0 check
    //         if(i > idx && num[idx] == '0'){
    //             break;
    //         }
            
    //         string currStr = num.substr(idx, i - idx + 1);
    //         long currNum = stol(currStr);

    //         if(idx == 0){
    //             solve(num, target, result, currNum, currNum, i+1, currStr);
    //         } else {
    //             solve(num, target, result, temp + currNum, currNum, i+1, s + "+" + currStr);

    //             solve(num, target, result, temp - currNum, -currNum, i+1, s + "-" + currStr);

    //             solve(num, target, result, temp - prevNum + (prevNum * currNum), prevNum * currNum, i+1, s + "*" + currStr);

    //         }

    //    }
    // }

    
    // APPROACH 2
    // TC -> O(4^N * N)
    // SC -> O(N)

    void solve(string& num, int target, vector<string>& result, long temp, long prev, int idx, string& s){

        if(idx == num.length()){
            if(temp == target){
                result.push_back(s);
            }
            return;
        }

        for(int i = idx; i < num.length(); i++){

            if(i > idx && num[idx] == '0') break;

            string currStr = num.substr(idx, i - idx + 1);
            long currNum = stol(currStr);
            int len = currStr.size();

            if(idx == 0){
                s += currStr;
                solve(num, target, result, currNum, currNum, i + 1, s);
                s.erase(s.size() - len);
            }
            else {
                s += "+" + currStr;
                solve(num, target, result, temp + currNum, currNum, i+1, s);
                s.erase(s.size() - len - 1);

                s += "-" + currStr;
                solve(num, target, result, temp - currNum, -currNum, i+1, s);
                s.erase(s.size() - len - 1);

                s += "*" + currStr;
                solve(num, target, result, temp - prev + (prev * currNum), prev * currNum, i+1, s);
                s.erase(s.size() - len - 1);

            }

        }
    }

    vector<string> addOperators(string num, int target) {
        
        vector<string> result;
        string s = "";
        solve(num, target, result, 0, 0, 0, s);
        return result;
    }
};