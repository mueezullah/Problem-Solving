class Solution {
public:
    // TC -> O(n^2)
    // SC -> O(1)
    int expand(string& s, int left, int right, int n){
        while(left >= 0 && right < n && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left - 1;
    }

    string longestPalindrome(string s) {
        int n = s.length();

        if(n == 0) return "";
        
        int start = 0, maxLen = 1;

        for(int i = 0; i < n; i++){
            
            int even = expand(s, i, i + 1, n); // even case    
            int odd = expand(s, i, i, n); // odd case
            
            int maxi = max(odd, even);

            if(maxi > maxLen){
                maxLen = maxi;
                start = i - (maxi - 1) / 2;
            }

        }
        return s.substr(start, maxLen);
    }
};