class Solution {
public:
    bool solveRec(string& s, int i, int j){
        if(i >= j){
            return true;
        }

        if(!isalnum(s[i])){
            return solveRec(s, ++i, j);
        }
        if(!isalnum(s[j])){
            return solveRec(s, i, --j);
        }
        
        if(tolower(s[i]) != tolower(s[j])){
            return false;
        }

        return solveRec(s, ++i, --j);
    }

    // custom function to check if char is alpha numeric
    // bool isAlphaNum(char ch){
    //     if((ch >= '0' && ch <= '9') ||
    //         (tolower(ch) >= 'a' && tolower(ch) <= 'z')){
    //             return true;
    //     }
    //     return false;
    // }

    bool isPalindrome(string s) {
        // APPROACH 1 (Two Pointer)
        // TC -> O(n)
        // SC -> O(1)

        // int n = s.length();
        // int i = 0, j = n - 1;

        // while(i < j){

        //     // In-built STL to use instead custom func so both will work
        //     // while(i < j && !isalnum(s[i]))
        //     while(i < j && !isAlphaNum(s[i])){
        //         i++;
        //     }
        //     // skip non-alphaNumeric
        //     while(i < j && !isAlphaNum(s[j])){
        //         j--;
        //     }

        //     if(tolower(s[i]) != tolower(s[j])){
        //         return false;
        //     }

        //     i++;
        //     j--;
        // }
        // return true;


        // APPROACH 2 (Recursion)
        // TC -> O(n)
        // SC -> O(n)

        int n = s.length();
        int i = 0, j = n-1;

        return solveRec(s, i, j);
    }
};