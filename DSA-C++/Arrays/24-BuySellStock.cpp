class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // APPROACH 1 (2 Pass + Extra space)
        // vector<int> maxRight(n);

        // maxRight[n-1] = prices[n-1];
        // for(int i = n-2; i >= 0; i--){
        //     maxRight[i] = max(maxRight[i+1], prices[i]);
        // }

        // int profit = 0;
        // for(int i = 0; i < n; i++){
        //     profit = max(profit, maxRight[i] - prices[i]);
        // }
        // return profit;

        // APPROACH 2 (1 Pass)
        int mini = prices[0];
        int profit = 0;

        for(int i = 1; i < n; i++){
            if(mini > prices[i]){
                mini = prices[i];
            }

            profit = max(profit, prices[i] - mini);
        }
        return profit;
    }
};