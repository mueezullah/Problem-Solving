class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // TC -> O(n)
        // SC -> O(1)
        vector<int> freq(26, 0);
        for(char c : tasks){
            freq[c - 'A']++;
        }

        priority_queue<int> pq;
        for(int i : freq){
            if(i > 0){
                pq.push(i);
            }
        }

        int time = 0;

        while(!pq.empty()){

            vector<int> temp;
            for(int i = 1; i <= n+1; i++){

                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }
            
            for(int t : temp){
                if(t > 0){
                    pq.push(t);
                }
            }

            if(pq.empty()){
                time += temp.size();
            } else {
                time += n + 1;
            }
        }
        return time;
    }
};