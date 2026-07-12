class Solution {
public:
    string stringProcess(string s){
        stack<char> st;

        for(char c : s){

            if(st.size() > 0 && c == '#'){
                st.pop();
            }
            else if(st.size() == 0 && c == '#'){
                continue;
            }
            else {
                st.push(c);
            }
        }

        string ans = "";
        while(st.size() != 0){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());

        return ans;
    }

    string stringAppTwo(string &s){

        string ans = "";
        int n = s.length();

        int i = 0;
        while(i < n){
            if(s[i] != '#'){
                ans.push_back(s[i]);
            }
            else if(ans.length() > 0) {
                ans.pop_back();
            }
            i++;
        }
        return ans;
    }

    bool backspaceCompare(string s, string t) {
        // APPROACH 1 (Stack)
        // TC -> O(n + m)
        // SC -> O(n + m)

        // return stringProcess(s) == stringProcess(t);

        // APPROACH 2 (String)
        // TC -> O(n + m)
        // SC -> O(n + m)

        // return stringAppTwo(s) == stringAppTwo(t);

        // APPROACH 3 (Optimal)
        // TC -> O(n + m)
        // SC -> O(1)

        int n = s.length();
        int m = t.length();

        int i = n-1;
        int j = m-1;

        int countS = 0;
        int countT = 0;

        while(i >= 0 || j >= 0){

            while(i >= 0){
                if(s[i] == '#'){
                    countS++;
                    i--;
                }
                else if(countS > 0){
                    countS--;
                    i--;
                }
                else {
                    break;
                }
            }

            while(j >= 0){
                if(t[j] == '#'){
                    countT++;
                    j--;
                }
                else if(countT > 0){
                    countT--;
                    j--;
                }
                else {
                    break;
                }
            }

            if(i >= 0 && j >= 0 && s[i] != t[j]){
                return false;
            }
            if((i >= 0) != (j >= 0)){
                return false;
            }
            i--;
            j--;
        }
        return true;

    }
};