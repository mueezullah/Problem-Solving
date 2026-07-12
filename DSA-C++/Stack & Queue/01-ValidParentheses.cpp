class Solution {
public:
    bool isValid(string s) {
        // TC -> O(n)
        // SC -> O(n)
        
        stack<char> st;

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];

            if(ch == '(' || ch == '[' || ch == '{'){ // opening case
                st.push(ch);
            }
            else { // closing case

                if(st.size() == 0){
                    return false;
                }

                if((st.top() == '(' && ch == ')') ||
                    (st.top() == '[' && ch == ']') ||
                    (st.top() == '{' && ch == '}')){
                        st.pop();
                }
                else { // no match
                    return false;
                }

            }
        }
        return st.size() == 0 ? true : false;
    }
};