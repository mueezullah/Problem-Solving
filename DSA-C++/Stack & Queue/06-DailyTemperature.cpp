class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);

        stack<pair<int, int>> st;

        for(int i = 0; i < n; i++){

            int currTemp = temperatures[i];

            while(!st.empty() && st.top().first < currTemp){
                
                int prevIdx = st.top().second;
                st.pop();

                ans[prevIdx] = i - prevIdx;
            }

            st.push({currTemp, i});
        }

        return ans;

    }
};