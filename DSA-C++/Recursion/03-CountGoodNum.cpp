class Solution {
public:
    const int M = 1e9+7; // 10^9 + 7

    // int findPower(long long a, long long b){
    //     if(b == 0) return 1;

    //     long long half = findPower(a, b/2);
    //     long long result = (half * half) % M;

    //     if(b % 2 == 1){
    //         result = (result * a) % M;
    //     }

    //     return result;
    // }

    int findPowerItr(long long a, long long b){

        long long result = 1;
        a %= M;

        while(b > 0){

            if(b % 2 == 1){
                result = (result * a) % M;
            }

            a = a * a % M;
            b /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        // APPROACH 1 (Recursion)
        // TC -> O(log n)
        // SC -> O(log n)

        // Chars at even indices are even digits → 0,2,4,6,8 = 5 choices
        // Chars at odd indices are prime digits → 2,3,5,7 = 4 choices
        //return (long long)findPower(5, (n+1)/2) * findPower(4, (n/2)) % M;

        // APPROACH 2 (Iterative)
        // TC -> O(log n)
        // SC -> O(1)

        return (long long)findPowerItr(5, (n+1)/2) * findPowerItr(4, (n/2)) % M;

    }
};