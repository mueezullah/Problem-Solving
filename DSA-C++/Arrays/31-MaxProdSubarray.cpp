class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // APPROACH 1 (Brute force) Gives TLE
        // int n = nums.size();
        // int maxi = INT_MIN;

        // for(int i = 0; i < n; i++){
        //     int product = 1;
        //     for(int j = i; j < n; j++){

        //         product *= nums[j];
        //         maxi = max(maxi, product);

        //         if(product == 0){
        //             break;
        //         }
        //     }
        // }
        // return maxi;

        // APPROACH 2
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

        // APPROACH 3
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

            maxi = max(maxi, max(pre, suff));
        }
        return maxi;
    }
};