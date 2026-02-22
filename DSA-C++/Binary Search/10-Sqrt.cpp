class Solution {
public:
    int mySqrt(int x) {
        // APPROACH 1 (Brute Force)
        // TC -> O(n)
        // SC -> O(1)
        // int ans = 0;

        // for(int i = 1; i <= x; i++){
        //     if((long long)i * i <= x){
        //         ans = i;
        //     }
        //     else {
        //         break;
        //     }
        // }
        // return ans;

        // APPROACH 2 (Binary Search)
        // TC -> O(log n)
        // SC -> O(1)
        int start = 1, end = x / 2, ans = 0;

        if(x < 2) return x;

        while(start <= end){
            long long mid = start + (end - start) / 2;

            if (mid * mid <= x){
                ans = mid;
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return ans;
    }
};