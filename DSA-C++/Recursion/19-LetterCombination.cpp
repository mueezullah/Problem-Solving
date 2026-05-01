class Solution {
public:
    // TC -> O(4^n * n)
    // SC -> O(n)

    void solve(string digits, int idx, string& curr, vector<string>& result, unordered_map<char, string> mp){
        
        if(idx == digits.length()){
            result.push_back(curr);
            return;
        }

        char ch = digits[idx];
        string str = mp[ch];

        for(int i = 0; i < str.length(); i++){

            curr.push_back(str[i]);
            solve(digits, idx + 1, curr, result, mp);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if(digits.length() == 0){
            return {};
        }

        vector<string> result;
        string curr = "";

        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        solve(digits, 0, curr, result, mp);
        return result;
    }
};