class Solution {
public:
    string removeStars(string s) {
        // APPROACH 1 (Stack)
        // TC -> O(N)
        // SC -> O(N)
        // stack<char> st;
        // int n = s.length();
        // int i = 0;

        // while(i < n){

        //     if(!st.empty() && s[i] == '*'){
        //         st.pop();
        //     }
        //     else{
        //         st.push(s[i]);
        //     }
        //     i++;
        // }

        // string ans = "";
        // while(!st.empty()){
        //     ans.push_back(st.top());
        //     st.pop();
        // }

        // reverse(ans.begin(), ans.end());

        // return ans;

        // APPROACH 2 (String)
        // TC -> O(N)
        // SC -> O(N)

        // int n = s.length();
        // int i = 0;
        // string ans = "";

        // while(i < n){

        //     if(ans.size() != 0 && s[i] == '*'){
        //         ans.pop_back();
        //     }
        //     else {
        //         ans.push_back(s[i]);
        //     }
        //     i++;
        // }
       
        // return ans;

        // APPROACH 3 (TWo pointers)
        // TC -> O(N)
        // SC -> O(1)

        int j = 0;

        for(int i = 0; i < s.length(); i++){

            if(s[i] == '*'){
                j--;
            }
            else {
                s[j] = s[i];
                j++;
            }
        }

        return s.substr(0, j);
    }
};
