class Solution {
public:
    string removeDuplicates(string s) {
        // APPROACH 1
        // TC -> O(n)
        // SC -> O(n)

        // stack<char> st;
        // string ans = "";

        // for(int i = 0; i < s.length(); i++){

        //     if(st.size() > 0 && s[i] == st.top()){
        //         st.pop();
        //     }
        //     else {
        //         st.push(s[i]);
        //     }
            
        // }
        // while(st.size() != 0){
        //     ans.push_back(st.top());
        //     st.pop();
        // }

        // reverse(ans.begin(), ans.end());

        // return ans;

        // APPROACH 2
        // TC -> O(n)
        // SC -> O(n)

        string ans = "";

        for(char c : s){

            if(!ans.empty() && ans.back() == c){
                ans.pop_back();
            }
            else {
                ans.push_back(c);
            }
        }

        return ans;
    }
};