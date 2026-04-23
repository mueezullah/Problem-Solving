class Solution {
public:
    bool isPowerOfThree(int n) {
        // APPROACH 1 (Iterative Division)
        // TC -> O(log₃ n)
        // SC -> O(1)

        // if(n <= 0) 
        //     return false;
        
        // while(n % 3 == 0){
        //     n /= 3;
        // }
        // return n == 1;

        // APPROACH 2 (Recursion)
        // TC -> O(log₃ n)
        // SC -> O(log₃ n)

        // if(n <= 0)
        //     return false;
        
        // if(n == 1)
        //     return true;

        // if(n % 3 != 0)
        //     return false;

        // return isPowerOfThree(n / 3);

        // APPROACH 3 (Logarithm Math)
        // If n is a power of 3, then log₃(n) must be a perfect integer (no decimals)
        // TC -> O(1)
        // SC -> O(1)

        // if(n <= 0)
        //     return false;

        // double x = log10(n) / log10(3);

        // return x == (int)x;

        // APPROACH 4 (Bit Manipulation)
        // TC -> O(1)
        // SC -> O(1)


        return (n > 0) && (1162261467 % n == 0);
    }
};