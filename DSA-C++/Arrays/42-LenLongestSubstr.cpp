class Solution {
public:
    // APPROACH 1 (Brute Force)
    // TC -> O(n^2)
    // SC -> O(m) m = 256
    int lengthOfLongestSubstring(string s) {
        
    //     int n = s.length();
    //     int maxLen = 0;

    //     for(int i = 0; i < n; i++){

    //         unordered_set<char> st(265);

    //         for(int j = i; j < n; j++){
                
    //             if(st.find(s[j]) != st.end()){
    //                 break;
    //             }

    //             st.insert(s[j]);
    //             maxLen = max(maxLen, j - i + 1);
    //         }
    //     }
    //     return maxLen;

        // APPROACH 2 (Sliding Window + Two pointers)
        // TC -> O(n)
        // SC -> O(m) m = 256
        
        int n = s.length();
        int maxLen = 0;

        int left  = 0;
        int right = 0;

        unordered_map<char, int> mp(256);

        while(right < n){
            
            char r = s[right];
            mp[r]++;

            while(mp[r] > 1){
                
                char l = s[left];
                mp[l]--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
            right++;

        }
        return maxLen;
    }
};