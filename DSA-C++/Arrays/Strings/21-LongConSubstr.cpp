class Solution {
public:
    int longestContinuousSubstring(string s) {
        // APPROACH 1 (Brute Force)
        // TC -> O(n^2)
        // SC -> O(1)
        
        // int n = s.length();
        // int maxLen = 1;

        // for(int i = 0; i < n; i++){
            
        //     int currLen = 1;
        //     for(int j = i+1; j < n; j++){

        //         if(s[j] - s[j-1] == 1){
                    
        //             currLen++;
        //             maxLen = max(maxLen, currLen);
        //         } else {
        //             break;
        //         }
        //     }
            
        // }
        // return maxLen;


        // APPROACH 2 (Sliding window)
        // TC -> O(n)
        // SC -> O(1)

        int n = s.length();
        int maxLen = 1;
        int currLen = 1;

        for(int i = 1; i < n; i++){

            if(s[i] - s[i-1] == 1){
                
                currLen++;
                maxLen = max(maxLen, currLen);
            } else {
                currLen = 1;
            }
        }
        return maxLen;
    }
};