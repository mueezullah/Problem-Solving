class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // APPROACH 1 (TLE)
        // TC -> O(N^2)
        // SC -> O(1)
        
        // int n = cardPoints.size();
        // int maxSum = 0;

        // for(int i = 0; i <= k; i++){
        //     int sum = 0;

        //     for(int l = 0; l < i; l++){
        //         sum += cardPoints[l];
        //     }

        //     for(int r = n-1; r >= n-(k-i); r--){
        //         sum += cardPoints[r];
        //     }

        //     maxSum = max(maxSum, sum);
        // }

        // return maxSum;

        // APPROACH 2 (Sliding Window + Two Pointers)
        // TC -> O(N)
        // SC -> O(1)

        int n = cardPoints.size();
        int lSum = 0;
        int rSum = 0;
        int maxSum = 0;

        for(int i = 0; i < k; i++){
            lSum += cardPoints[i];
        }
        
        maxSum = lSum;
        int rIdx = n - 1;

        for(int i = k-1; i >= 0; i--){
            lSum -= cardPoints[i];
            rSum += cardPoints[rIdx];
            rIdx--;

            maxSum = max(maxSum, lSum + rSum);
        }
        
        return maxSum;
    }
};