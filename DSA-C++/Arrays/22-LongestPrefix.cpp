class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        string ans = "";
        int n = strs.size();

        for(int i = 0; i < strs[0].size(); i++){
            char ch = strs[0][i];

            for(int j = 1; j < n; j++){
                if(strs[j].size() <= i || ch != strs[j][i]){
                    return ans;
                }
            }
            ans.push_back(ch);
        }
        return ans;
    }
};