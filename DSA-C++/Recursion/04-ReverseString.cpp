class Solution {
public:
    void solve(vector<char>& s, int i, int j){
        if(i >= j){
            return;
        }
        swap(s[i], s[j]);

        solve(s, ++i, --j);
    }
    
    void reverseString(vector<char>& s) {
        // APPROACH 1 (Built-in STL)
        // TC -> O(n)
        // SC -> O(1)

        // reverse(s.begin(), s.end());

        // APPROACH 2 (Two Pointers) optimized
        // TC -> O(n)
        // SC -> O(1)

        // int n = s.size();
        // int i = 0, j = n-1;

        // while(i < j){
        //     swap(s[i], s[j]);
        //     i++;
        //     j--;
        // }

        // APPROACH 3 (Recursion)
        // TC -> O(n)
        // SC -> O(n)

        int n = s.size();
        int i = 0, j = n-1;

        solve(s, i, j);


    }
};