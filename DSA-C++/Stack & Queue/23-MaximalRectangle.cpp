class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& heights, vector<int>& next, int n){
        
        stack<int> st;

        for(int i = n-1; i >= 0; i--){

            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return next;
    }

    vector<int> prevSmallerElement(vector<int>& heights, vector<int>& prev, int n){

        stack<int> st;

        for(int i = 0; i < n; i++){

            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return prev;
    }

    int largestRectangleArea(vector<int>& heights, int cols){
        int n = heights.size();

        vector<int> nse(n);
        vector<int> pse(n);

        nse = nextSmallerElement(heights, nse, n);
        pse = prevSmallerElement(heights, pse, n);

        int maxArea = 0;
        for(int i = 0; i < n; i++){
            int width = nse[i] - pse[i] - 1;
            int area = width * heights[i];

            maxArea = max(maxArea, area);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        // TC -> O(rows * cols)
        // SC -> O(cols)
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);
        int ans = 0;

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){

                heights[c] = (matrix[r][c] == '1') ? heights[c] + 1 : 0;
            }
            ans = max(ans, largestRectangleArea(heights, cols));
        }

        return ans;
    }
};