class Solution {
public:
    int minOperations(vector<string>& logs) {
        // APPROACH 1 (Stack)
        // TC -> O(n)
        // SC -> O(n)

        // stack<string> st;

        // for(int i = 0; i < logs.size(); i++){
        //     if(logs[i] == "../"){
        //         if(st.size() > 0){
        //             st.pop();
        //         }
        //     }
        //     else if(logs[i] == "./"){
        //         continue;
        //     }
        //     else {
        //         st.push(logs[i]);
        //     }
        // }
        // return st.size();

        // APPROACH 2 (String) Optimal
        // TC -> O(n)
        // SC -> O(1)

        int depth = 0;

        for(int i = 0; i < logs.size(); i++){

            if(logs[i] == "../"){
                depth = max(0, depth-1);
            }
            else if(logs[i] == "./"){
                continue;
            }
            else { // case '/'
                depth++;
            }
        }
        return depth;
    }
};