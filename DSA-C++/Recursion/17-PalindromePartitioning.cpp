class Solution {
public:
    bool isPalindrome(string s, int left, int right){

        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void solve(string s, int index, vector<vector<string>>& result, vector<string>& curr){

        if(index == s.length()){
            result.push_back(curr);
            return;
        }

        for(int i = index; i < s.length(); i++){

            if(isPalindrome(s, index, i)){

                curr.push_back(s.substr(index, i - index + 1));

                solve(s, i + 1, result, curr);

                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> result;
        vector<string> curr;

        solve(s, 0, result, curr);
        return result;
    }
};