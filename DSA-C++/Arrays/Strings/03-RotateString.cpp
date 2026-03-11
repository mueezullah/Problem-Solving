class Solution {
public:
    bool rotateString(string s, string goal) {
        // APPROACH 1 
        // TC -> O(n^2)
        // SC-> O(1)
        // int n = s.length();
        // int m = goal.length();

        // if(n != m) return false;

        // int i = 0;

        // while(i < n){
        //     rotate(s.begin(), s.begin()+1, s.end());

        //     if(s == goal){
        //         return true;
        //     }

        //     i++;
        // }

        // return false;

        // APPROACH 2
        // TC -> O(n)
        // SC -> O(2n) -> O(n)
        
        int n = s.length();
        int m = goal.length();

        if(n != m) return false;

        string doubled = s + s;

        if(doubled.find(goal) != string::npos){
            return true;
        }
        return false;
    } 
};