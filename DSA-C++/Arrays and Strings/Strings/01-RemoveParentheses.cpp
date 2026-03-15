class Solution {
public:
    string removeOuterParentheses(string s) {
        // TC -> O(n)
        // SC -> O(n)
        string ans = "";
        int count = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                if(count > 0){
                    ans += '(';
                }
                count++;
            }
            else{ // s[i] == ')'
                if(count > 1){
                    ans += ')';
                }
                count--;
            }
        }
        return ans;
    }
};