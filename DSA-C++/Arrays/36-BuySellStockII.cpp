class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // TC -> O(n)
        // SC -> O(1)
        int buy = 0, sell = 0;
        int total = 0;

        for(int i = 1; i < prices.size(); i++){

            if(prices[i] > prices[i - 1]){
                buy = prices[i - 1];
                sell = prices[i];
                total += sell - buy;
            }
        }
        return total;
    }
};