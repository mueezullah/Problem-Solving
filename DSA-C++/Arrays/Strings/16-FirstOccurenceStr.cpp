class Solution {
public:
    int strStr(string haystack, string needle) {
        // APPROACH 1
        // TC -> O(n*m)
        // SC -> O(1)
        // int n = haystack.length();
        // int m = needle.length();
        
        // if(m > n) return -1;
        
        // for(int i = 0; i <= n - m; i++){
        //     if(haystack.substr(i, m) == needle) return i;
        // }
        // return -1;

        // APPROACH 2
        // TC -> O(n*m)
        // SC -> O(1)

        int n = haystack.length();
        int m = needle.length();

        for(int i = 0; i <= n - m; i++){
            for(int j = 0; j < m; j++){

                if(haystack[i+j] != needle[j]){
                    break;
                }

                if(j == m-1){
                    return i;
                }
            }
        }
        return -1;
    }
};