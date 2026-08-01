class Solution {
public:
    int minSwaps(string s) {
        // APPROACH 1 (Stack)
        // TC -> O(n)
        // SC -> O(n)

        // stack<char> st;

        // for(int i = 0; i < s.length(); i++){
            
        //     if(s[i] == '['){
        //         st.push(s[i]);
        //     }
        //     else if(!st.empty()){
        //         st.pop();
        //     }
        // }

        // return (st.size() + 1) / 2;

        // APPROACH 2 (Optimal)
        // TC -> O(n)
        // SC -> O(n)

        int size = 0;

        for(int i = 0; i < s.length(); i++){

            if(s[i] == '['){
                size++;
            }
            else if(size > 0){
                size--;
            }
        }

        return (size + 1) / 2;
    }
};