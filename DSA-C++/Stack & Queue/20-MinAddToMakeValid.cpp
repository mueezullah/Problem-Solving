class Solution {
public:
    int minAddToMakeValid(string s) {
        // APPROACH 1 (Stack)
        // TC -> O(n)
        // SC -> O(n)
        
        // stack<int> st;
        // int closes = 0;
        
        // for(char ch : s){

        //     if(ch == '('){
        //         st.push(ch);
        //     }
        //     else { // ch == ')'
        //         if(!st.empty()){
        //             st.pop();
        //         }
        //         else {
        //             closes++;
        //         }
        //     }

        // }

        // return closes + st.size();


        // APPROACH 2 (Optimal)
        // TC -> O(n)
        // SC -> O(1)

        int open = 0;
        int size = 0;

        for(char ch : s){

            if(ch == '('){
                size++;
            }
            else if(size > 0 && ch == ')'){
                size--;
            }
            else{
                open++;
            }
        }

        return open + size;
    }
};