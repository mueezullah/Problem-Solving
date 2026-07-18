class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        stack<int> st;

        for(int i = 0; i < operations.size(); i++){

            if(operations[i] == "+"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();

                int sum = first + second;
                st.push(second);
                st.push(first);
                st.push(sum);
            }
            else if(operations[i] == "D"){
                int doubleScore = st.top()*2;
                
                st.push(doubleScore);
            }
            else if(operations[i] == "C"){
                st.pop();
            } else{
                st.push(stoi(operations[i]));
            }
        }

        int result = 0;
        while(!st.empty()){
            result += st.top();
            st.pop();
        }

        return result;
    }
};