// class Solution {
// public:
//     // APPROACH 1
//     // TC -> O(2^2n * 2n) solve-> 2^2n possibilities, 
//     // isValid-> 2n
//     // SC -> O(2 * n) depth of recursion tree

//     vector<string> result;

//     bool isValid(string str){
//         int depth = 0;

//         for(char ch : str){
//             if(ch == '('){
//                 depth++;
//             }
//             else {
//                 depth--;
//             }

//             if(depth < 0){
//                 return false;
//             }
//         }

//         return depth == 0;
//     }

//     void solve(string& ans, int n){

//         if(ans.length() == 2*n){
//             if(isValid(ans)){
//                 result.push_back(ans);
//             }
//             return;
//         }

//         ans.push_back('(');
//         solve(ans, n);
//         ans.pop_back();

//         ans.push_back(')');
//         solve(ans, n);
//         ans.pop_back();
//     }

//     vector<string> generateParenthesis(int n) {
//         string ans = "";

//         solve(ans, n);
//         return result;
//     }
// };

class Solution {
public:

    // APPROACH 2
    // TC -> O(2^2n) 2^2n possibilities, 
    // SC -> O(2 * n) depth of recursion tree

    vector<string> result;

    void solve(string& ans, int n, int open, int close){
        if(ans.length() == 2*n){
            result.push_back(ans);
            return;
        }

        if(open < n){
            ans.push_back('(');
            solve(ans, n, open+1, close);
            ans.pop_back();
        }
        if(close < open){
            ans.push_back(')');
            solve(ans, n, open, close+1);
            ans.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string ans = "";
        int open = 0, close = 0;

        solve(ans, n, open, close);

        return result;
    }
};