class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        string ans = "";

        for(int i = n - 1; i >= 0; i--){
            int lastOdd = num[i] - '0';

            if(lastOdd % 2 == 1){
                return num.substr(0, i+1);
            }
        }
        return "";
    }
};