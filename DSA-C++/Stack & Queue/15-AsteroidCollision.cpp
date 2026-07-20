class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // TC -> O(n)
        // SC -> O(n)
        stack<int> st;
        int n = asteroids.size();

        for(int i = 0; i < n; i++){

            while(!st.empty() && asteroids[i] < 0 && st.top() > 0){
                int sum = asteroids[i] + st.top();
                if(sum < 0){
                    st.pop();
                } else if(sum > 0){
                    asteroids[i] = 0;
                    break;
                } else {
                    st.pop();
                    asteroids[i] = 0;
                    break;
                } 
            }

            if(asteroids[i] != 0){
                st.push(asteroids[i]);
            }
        }

        int stackSize = st.size();
        vector<int> ans(stackSize);

        int i = stackSize-1;
        while(!st.empty()){
            ans[i] = st.top();
            st.pop();
            i--;
        }

        return ans;
    }
};