class Solution {
public:
    string minWindow(string s, string t) {
        // TC -> O(n + m)
        // SC -> O(1)
        int n = s.length();
        int m = t.length();

        if(m > n) return "";

        unordered_map<char, int> mp;
        for(int num : t){
            mp[num]++;
        }

        int requiredCount = m;
        int left = 0, right = 0;
        int minWindowLen = INT_MAX;
        int startLeft = 0;

        while(right < n){
            char ch = s[right];

            if(mp[ch] > 0){
                requiredCount--;
            }
            mp[ch]--;

            while(requiredCount == 0){
                int currWindow = right - left + 1;

                if(currWindow < minWindowLen){
                    minWindowLen  = currWindow;
                    startLeft = left;
                }
                mp[s[left]]++;
                if(mp[s[left]] > 0){
                    requiredCount++;
                }
                left++;
            }
            right++;
        }
        return minWindowLen == INT_MAX ? "" : s.substr(startLeft, minWindowLen);
    }
};