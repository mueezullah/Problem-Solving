class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // APPROACH 1 (Sort)
        // TC -> O(n * n log n) OR (n^2 log n)
        // SC -> O(1)
        // while(stones.size() > 1){

        //     sort(stones.begin(), stones.end());
            
        //     int a = stones.back();
        //     stones.pop_back();
        //     int b = stones.back();
        //     stones.pop_back();

        //     stones.push_back(abs(a - b));
        // }

        // return stones[0];

        // APPROACH 2 (Heap)
        // TC -> O(n log n)
        // SC -> O(k)

        priority_queue<int> pq;
        
        for(int i : stones){
            pq.push(i);
        }

        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            pq.push(abs(a - b));
        }

        return pq.top();
    }
};