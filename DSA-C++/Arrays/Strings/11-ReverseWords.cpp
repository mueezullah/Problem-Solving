class Solution {
public:
    string reverseWords(string s) {
        // APPROACH 1
        // TC -> O(n)
        // SC -> O(n)
        int n = s.length();
        // string ans = "";
        
        // reverse(s.begin(), s.end());

        // for(int i = 0; i < n; i++){
            
        //     string word = "";
            
        //     while(i < n && s[i] != ' '){
        //         word += s[i];
        //         i++;
        //     }

        //     reverse(word.begin(), word.end());
        //     if(word.length() > 0){
        //         if(!ans.empty()){
        //             ans += " ";
        //         }
        //         ans += word;
        //     }
        // }
        // return ans;

        // APPROACH 2
        // TC -> O(n)
        // SC -> O(n)

        string ans = "";
        
        // last position
        int i = n - 1;

        while(i >= 0){
            // skip spaces from right
            while(i >= 0 && s[i] == ' '){
                i--;
            }
            // out of bound case
            if(i < 0) break;
            
            //end of current word
            int end = i;
            while(i >= 0 && s[i] != ' '){
                // i finding start of word here
                i--;
            }
            
            string word = s.substr(i + 1, end - i);

            if(!ans.empty()){
                ans += " ";
            }
            ans += word;
        }
        return ans;
    }
};