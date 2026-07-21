class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<int> st;
        int n = num.size();

        for(int i = 0; i < n; i++){

            while(!st.empty() && st.top() > num[i] && k > 0){
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }

        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        int start = 0;
        while(start < (int)ans.size() - 1 && ans[start] == '0'){
            start++;
        }

        ans = ans.substr(start);

        if(ans == ""){
            return "0";
        }

        return ans;
    }
};