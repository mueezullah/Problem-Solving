class Solution {
public:
    string sortSentence(string s) {
        // TC -> O(n)
        // SC -> O(n)
        
        string word = "";
        vector<string> vec(10);
        int n = 0;

        for(int i = 0; i < s.length(); i++){

            if(s[i] >= '1' && s[i] <= '9'){ // digit finding
                int pos = s[i] - '0';
                vec[pos] = word; // place word at correct index in vector
                n = max(n, pos); // track how many words exists
                word = "";

            }
            else if(s[i] == ' '){ // skip spaces
                continue;
            }
            else { // building current word
                word += s[i];
            }
        }

        string ans = "";
        for(int i = 1; i <= n; i++){
            
            if(i != 1) ans += " ";      // add spaces between words
            ans += vec[i];
        }

        return ans;
    }
};