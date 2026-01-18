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

        // APPROACH 3 (One Map) -> if character set is unknown
        unordered_map<char,int> count;
        for(char c : s) count[c]++;
        for(char c : t) count[c]--;

        for(auto temp : count){
            if(temp.second != 0) return false;
        }
        return true;
    }
};