class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& arr, int n){
        
        stack<int> st;
        vector<int> NSE(n, 0);

        for(int i = n-1; i >= 0; i--){

            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

            NSE[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return NSE;
    }

    vector<int> prevSmallerElement(vector<int>& arr, int n){

        stack<int> st;
        vector<int> PSE(n, 0);

        for(int i = 0; i < n; i++){

            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            PSE[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return PSE;
    }

    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        long long sum =  0;
        int M = 1e9+7;

        vector<int> NSE = nextSmallerElement(arr, n);
        vector<int> PSE = prevSmallerElement(arr, n);

        for(int i = 0; i < n; i++){

            long long ls = PSE[i] - i;
            long long rs = i - NSE[i];

            long long totalWays = ls * rs;

            long long totalSum = arr[i] * totalWays;

            sum = (sum + totalSum) % M;
        }

        return sum;
    }
};