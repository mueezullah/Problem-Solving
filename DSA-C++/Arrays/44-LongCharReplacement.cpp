class Solution {
public:
    int characterReplacement(string s, int k) {
        // APPROACH 1 (TLE Solution)
        // TC -> O(n^2)
        // SC -> O(26) = O(1)
        
        // int n = s.length();
        // int maxLen = 0;

        // for(int i = 0; i < n; i++){

        //     int freq[26] = {0};
        //     int maxFreq = 0;

        //     for(int j = i; j < n; j++){
                
        //         freq[s[j] - 'A']++;
        //         maxFreq = max(maxFreq, freq[s[j] - 'A']);

        //         int windowLen = j - i + 1;
        //         int replacementNeeded = windowLen - maxFreq;

        //         if(replacementNeeded <= k){
        //             maxLen = max(maxLen, windowLen);
        //         }
        //     }
        // }
        // return maxLen;

        // APPROACH 2 (Sliding Window + Two Pointers)
        // TC -> O(n)
        // SC -> O(1)

        int n = s.length();
        int freq[26] = {0};
        int maxLen = 0;
        int left = 0;
        int maxFreq = 0;

        for(int right = 0; right < n; right++){

            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            int windowLen = right - left + 1;
            int replacementNeeded = windowLen - maxFreq;

            if(replacementNeeded > k){
                freq[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};