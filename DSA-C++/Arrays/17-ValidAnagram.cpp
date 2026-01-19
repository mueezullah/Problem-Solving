class Solution {
public:
    bool isAnagram(string s, string t) {
        // APPROACH 1 (Sorting)
        // if(s.size() != t.size()){
        //     return false;
        // }
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());

        // return s == t;

        // APPROACH 2 (Two Maps)
        // if(s.size() != t.size()) return false;

        // unordered_map<char, int> countS;
        // unordered_map<char, int> countT;

        // for(int i = 0; i < s.size(); i++){
        //     countS[s[i]]++;
        //     countT[t[i]]++;
        // }
        // return countS == countT;

        // APPROACH 3 (1 Map) if character set is unknown (upper + lowercase + symbols etc)
        // unordered_map<char,int> count;
        // for(char c : s) count[c]++;
        // for(char c : t) count[c]--;

        // for(auto temp : count){
        //     if(temp.second != 0) return false;
        // }
        // return true;

        // APPROACH 4 (1 Array) if only lower english letters
        if(s.size() != t.size()){
             return false;
        }

        int freq[26] = {0};
        for(char c : s) freq[c - 'a']++;
        for(char c : t) freq[c - 'a']--;

        for(int i = 0; i < 26; i++){
            if(freq[i] != 0){
                return false;
            }
        }
        return true;
    }
};