class Solution {
public:
    bool isPowerOfFour(int n) {
        // APPROACH 1 (Iterative)
        // TC -> O(log₄ n)
        // SC -> O(1)

        // if (n <= 0)
        //     return false;
        
        // while(n % 4 <= 0){
        //     n /= 4;
        // }

        // return n == 1;

        // APPROACH 2 (Recursive)
        // TC -> O(log₄ n)
        // SC -> O(log₄ n)

        // if(n <= 0)
        //     return false;

        // if(n == 1)
        //     return true;

        // if(n % 4 != 0)
        //     return false;
        
        // return isPowerOfFour(n / 4);

        // APPROACH 3 (Logarithm maths)
        // TC -> O(1)
        // SC -> O(1)

        // if(n <= 0)
        //     return false;

        // double x = (log(n) / log(4));   // compute log base 4 of n

        // if(pow(4, round(x)) == n)
        //     return true;

        // return false;

        // APPROACH 4 (Bit Magic)
        // TC -> O(1)
        // SC -> O(1)

        if(n <= 0)
            return false;

        bool pow2 = (n & (n - 1)) == 0;
        bool evenBit = (n - 1) % 3 == 0;

        return pow2 && evenBit;
    }
};