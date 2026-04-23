class Solution {
public:
    bool isPowerOfTwo(int n) {
        //APPROACH 1 (Recursion)
        // TC -> O(log n)
        // SC -> O(log n)
        
        // if(n <= 0) return false;
        // if(n == 1) return true;

        // return ((n % 2 == 0) && isPowerOfTwo(n/2));

        // APPROACH 3 (Iterative Division)
        // TC -> O(log n)
        // SC -> O(1)

        // if(n <= 0)
        //     return false;

        // while(n % 2 == 0){
        //     n /= 2;
        // }

        // return n == 1;


        // APPROACH 3 (Bit Manipulation)
        // TC -> O(1)
        // SC -> O(1)
        // return ((n > 0) && (n & (n - 1)) == 0 ? true : false);

        // APPROACH 4 (Built in Function) Count Bits
        // TC -> O(1)
        // SC -> O(1)

        if(n <= 0)
            return false;

        int count = __builtin_popcount(n);
        return count == 1;
    }
};