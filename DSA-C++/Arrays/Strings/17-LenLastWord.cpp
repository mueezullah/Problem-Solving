class Solution {
public:
    int lengthOfLastWord(string s) {
        // APPRAOCH 1
        // TC -> O(n)
        // SC -> (1) 
        // int n = s.length();
        // int count = 0;
        
        // // iterator
        // int i = n-1;

        // // skip spaces
        // while(i >= 0 && s[i] == ' '){
        //     i--;
        // }

        // // count characters of last word
        // while(i >= 0 && s[i] != ' '){
        //     count++;
        //     i--;
        // }
        // return count;

        // APPRAOCH 2
        // TC -> O(n)
        // SC -> O(1)

        int n = s.length();
        int count = 0;

        for(int i = n-1; i >= 0; i--){
            if(s[i] != ' '){
                count++;
            }
            else if(count > 0){
                break;
            }
        }
        return count;
    }
};