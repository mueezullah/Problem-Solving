class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // APPROACH 1 (Brute force)
        // TC -> O(n^2)
        // SC -> O(1)
        // int n = nums.size();
        // int maxi = INT_MIN;

        // for(int i = 0; i < n; i++){
        //     int product = 1;
        //     for(int j = i; j < n; j++){

        //         product *= nums[j];
        //         maxi = max(maxi, product);
        //     }
        // }
        // return maxi;

        // APPROACH 2 (Prefix -> left to right + Suffix -> right to left) TWo passes
        // TC -> O(n)
        // SC -> O(1)
        // int n = nums.size();
        // int product = 1;
        // int maxi = INT_MIN;

        // for(int i = 0; i < n; i++){
            
        //     product *= nums[i];
        //     maxi = max(product, maxi);
        //     if(product == 0){
        //         product = 1;
        //     }  
        // }
        // product = 1;
        // for(int i = n-1; i >= 0; i--){
            
        //     product *= nums[i];
        //     maxi = max(product, maxi);
        //     if(product == 0){
        //         product = 1;
        //     }  
        // }

        // return maxi;

        // APPROACH 3 (Prefix, Suffix) Single Pass
        // TC -> O(n)
        // SC -> O(1)
        int pre = 1, suff = 1;
        int n = nums.size();
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++){
            
            if(pre == 0){
                pre = 1;
            }
            if(suff == 0){
                suff = 1;
            }

            pre *= nums[i];
            suff *= nums[n - i - 1];
            
            int PreSuffMax = max(pre, suff);
            maxi = max(maxi, PreSuffMax);
        }
        return maxi;
    }
};