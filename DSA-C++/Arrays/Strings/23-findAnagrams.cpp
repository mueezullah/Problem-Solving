class Solution {
public:
    bool allZeros(vector<int>& freq){
        for(int i : freq){
            if(i != 0) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        vector<int> freq(26, 0);

        for(int i = 0; i < p.length(); i++){
            
            char ch = p[i];
            freq[ch - 'a']++;
        }

        int i = 0, j = 0;
        vector<int> result;
        int k = p.length();

        while(j < n){
            freq[s[j] - 'a']--;

            if(j - i + 1 == k){
                if(allZeros(freq)){
                    result.push_back(i);
                }

                freq[s[i] - 'a']++;
                i++;
            }
            j++;
        }

        return result;
    }
};