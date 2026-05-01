class Solution {
public:
    // TC -> O(3^4) = O(81) ≈ O(1)
    // SC -> O(n)
    bool isValid(string str){
        if(str[0] == '0'){
            return false;
        }

        int val = stoi(str);

        if(val > 255){
            return false;
        }

        return true; 
    }

    void solve(string s, int idx, int n, int dots, string curr, vector<string>& result){

        if(idx == n && dots == 4){
            curr.pop_back(); // removing last dot in ans
            result.push_back(curr);
            // result.push_back(curr.substr(0, curr.length() - 1));

            return;
        }

        if(idx + 1 <= n){
            solve(s, idx + 1, n, dots + 1, curr + s.substr(idx, 1) + ".", result);
        }

        if(idx + 2 <= n && isValid(s.substr(idx, 2))){
            solve(s, idx + 2, n, dots + 1, curr + s.substr(idx, 2) + ".", result);
        }
        
        if(idx + 3 <= n && isValid(s.substr(idx, 3))){
            solve(s, idx + 3, n, dots + 1, curr + s.substr(idx, 3) + ".", result);
        }

    }
    vector<string> restoreIpAddresses(string s) {
        
        int n = s.length();
        vector<string> result;
        string curr = "";

        if(s.length() > 12){
            return {};
        }

        int dots = 0;

        solve(s, 0, n, dots, curr, result);
        return result;
    }
};