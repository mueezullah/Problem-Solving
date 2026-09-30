class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // TC -> O(n log n)
        // SC -> O(n)
        int n = profits.size();

        vector<pair<int, int>> vec(n);

        for(int i = 0; i < n; i++){
            vec[i] = {capital[i], profits[i]};
        }

        sort(vec.begin(), vec.end());

        int i = 0;
        priority_queue<int> pq;

        while(k > 0){

            while(i < n && vec[i].first <= w){
                pq.push(vec[i].second);
                i++;
            }

            if(pq.empty()){
                break;
            }

            w += pq.top();
            pq.pop();
            k--;
        }

        return w;
    }
};