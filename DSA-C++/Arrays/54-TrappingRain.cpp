class Solution {
public:
    int trap(vector<int>& height) {
        // APPROACH 1 (Brute Force)
        // TC -> O(n^2)
        // SC -> O(1)
        // int n = height.size();
        // int totalWater = 0;

        // for(int i = 0; i < n; i++){

        //     int leftMax = 0;
        //     for(int j = 0; j <= i; j++){
        //         leftMax = max(leftMax, height[j]);
        //     }

        //     int rightMax = 0;
        //     for(int j = i; j < n; j++){
        //         rightMax = max(rightMax, height[j]);
        //     }

        //     totalWater += min(leftMax, rightMax) - height[i];
        // }

        // return totalWater;


        // APPROACH 2 (Prefix Arrays)
        // TC -> O(n)
        // SC -> O(n)
        // int n = height.size();
        // int ans = 0;

        // vector<int> leftMax(n, 0);
        // vector<int> rightMax(n, 0);

        // leftMax[0] = height[0];
        // rightMax[n-1] = height[n-1];

        // for(int i = 1; i < n; i++){
        //     leftMax[i] = max(leftMax[i-1], height[i]);
        // }

        // for(int i = n-2; i >= 0; i--){
        //     rightMax[i] = max(rightMax[i+1], height[i]);
        // }

        // for(int i = 0; i < n; i++){
        //     ans += min(leftMax[i], rightMax[i]) - height[i];
        // }

        // return ans;


        // APPROACH 3 (Two Pointer)
        // TC -> O(n)
        // SC -> O(1)

        int n = height.size();
        int l = 0, r = n - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;

        while(l < r){

            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);

            if(leftMax < rightMax){
                ans += (leftMax - height[l]);
                l++;
            }
            else {
                ans += (rightMax - height[r]);
                r--;
            }
        }

        return ans;
    }
};