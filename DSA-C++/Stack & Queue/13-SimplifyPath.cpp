class Solution {
public:
    string simplifyPath(string path) {
        
        string token = "";
        
        stack<string> st; 
        stringstream ss(path);

        while(getline(ss, token, '/')){

            if(token == "" || token == "."){
                continue;
            }
            
            if(token != ".."){
                st.push(token);
            }
            else if(!st.empty()) {
                st.pop();
            }
        }

        if(st.empty()){
            return "/";
        }

        string ans = "";

        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }

        return ans;
    }
};