class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // APPROACH 1 
        // TC -> O(n * k log k)
        // SC -> O(n * k)
        // int n = strs.size();

        // vector<vector<string>> result;

        // unordered_map<string, vector<string>> mp;

        // for(int i = 0; i < n; i++){
        //     string word = strs[i];

        //     sort(word.begin(), word.end());

        //     mp[word].push_back(strs[i]);
        // }

        // for(auto it : mp){
        //     result.push_back(it.second);
        // }
        // return result;

        // APPROACH 2
        // TC -> O(n * k)
        // SC -> O(n * k)

        int n = strs.size();

        unordered_map<string, vector<string>> mp; 
        vector<vector<string>> result;

        for(int i = 0; i < n; i++){
            vector<int> count(26, 0);
            
            for(char c : strs[i]){
                count[c - 'a']++;
            }

            string new_word = "";
            
            for(int freq : count){
                new_word += to_string(freq) + "#";
            }

            mp[new_word].push_back(strs[i]);
        }

        for(auto it : mp){
            result.push_back(it.second);
        }

        return result;
    }
};