class Solution {
public:
    double solve(double x, long n){
        //base case
        if(n == 0) 
            return 1;

        // negative
        if(n < 0){
            return solve(1/x, -n);
        }
        //even
        if(n % 2 == 0){
            return solve(x * x, n/2);
        }
        // odd case
        return x * solve(x * x, (n-1)/2);
    }

    double myPow(double x, int n) {
        // APPROACH 1 (Binary Exponentiation)
        // TC -> O(log n)
        // SC -> O(1)

        // long binaryForm = n;
        // double ans = 1;

        // // negative value
        // if(n < 0){
        //     x = 1/x;
        //     binaryForm = -binaryForm;
        // }

        // // positive value
        // while(binaryForm > 0){
        //     if(binaryForm % 2 == 1){
        //         ans *= x;
        //     }
        //     x *= x;
        //     binaryForm /= 2;
        // }
        // return ans;

        // APPROACH 2 (Recursion)
        // TC -> O(log n)
        // SC -> O(log n)

        double ans = solve(x, long(n));
        return ans;
    }
};