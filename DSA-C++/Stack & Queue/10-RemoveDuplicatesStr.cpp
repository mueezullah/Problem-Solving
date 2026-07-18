class Solution {
public:
    string removeDuplicates(string s, int k) {

        int n = s.length();
        stack<pair<char, int>> st;

        for(int i = 0; i < n; i++){

            // adding pair to stack
            if(st.empty() || (st.top().first != s[i])){
                st.push({s[i], 1});
            }
            // existing top element to match
            else {
                auto prev = st.top();
                st.pop();

                st.push({s[i], prev.second + 1});
            }
            // found k, remove immediately
            if(st.top().second == k){
                st.pop();
            }
        }

        string ans = "";
        while(!st.empty()){
            auto curr = st.top();
            st.pop();

            while(curr.second > 0){
                ans.push_back(curr.first);
                curr.second--;
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};