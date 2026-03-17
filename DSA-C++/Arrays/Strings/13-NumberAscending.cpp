class Solution {
public:
    bool areNumbersAscending(string s) {
        // APPROACH 1
        // TC -> O(n)
        // SC -> O(w) stroes one word at a time (w = longest word)

        // // split string by spaces automatically
        // istringstream ss(s);
        // string word;

        // int prev = -1;

        // // reading word by word from string
        // while(ss >> word){
        //     if(isdigit(word[0])){

        //         // convert string into integer, "12" -> 12
        //         int num = stoi(word); 

        //         if(num <= prev){
        //             return false;
        //         }
                
        //         prev = num;
        //     }
        // }
        // return true;

        // APPROACH 2
        // TC -> O(n)
        // SC -> O(1)

        int n = s.length();
        int prev = -1;
        int i = 0;

        while(i < n){
            if(isdigit(s[i])){

                int num = 0;
                
                // build number manually
                while(i < n && isdigit(s[i])){
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                
                if(num <= prev){
                    return false;
                }
                prev = num;
            }
            // skip letters and spaces
            else {
                i++;
            }
        }
        return true;
    }
};