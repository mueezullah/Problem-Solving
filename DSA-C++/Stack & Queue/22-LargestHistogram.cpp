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

    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();

        vector<int> next(n);
        vector<int> prev(n);

        next = nextSmallerElement(heights, next, n);
        prev = prevSmallerElement(heights, prev, n);

        int maxArea = 0;

        for(int i = 0; i < n; i++){

            int width = next[i] - prev[i] - 1;
            int area = heights[i] * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};