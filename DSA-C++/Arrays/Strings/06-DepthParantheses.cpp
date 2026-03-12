class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int ans = 0;

        for(char i = 0; i < s.length(); i++){
            if(s[i] == '('){   
                depth++;      
            }
            else if(s[i] == ')'){     
                depth--;
            }
            else {
                continue;
            }
            ans = max(ans, depth);
        }
        return ans;
    }
};