class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        // APPROACH 1 (Sorting)
        // TC -> O(n log n)
        // SC -> O(1)
        // int sum = 0;

        // for(int i = 0; i < piles.size(); i++){
        //     sum += piles[i];
        // }

        // sort(piles.begin(), piles.end());
        // int n = piles.size() - 1;

        // while(k > 0){
        //     int removed = piles[n] / 2;
        //     piles[n] -= removed;
        //     sum -= removed;

        //     sort(piles.begin(), piles.end());
        //     k--;
        // }

        // return sum;

        // APPROACH 2 (Heap)
        // TC -> O(n + k log n)
        // SC -> O(n)

        priority_queue<int> pq;

        int sum = 0;
        int n = piles.size();

        for(int i = 0; i < n; i++){
            pq.push(piles[i]);
            sum += piles[i];
        }

        while(k > 0){
            int maxPile = pq.top();
            pq.pop();

            int removed = maxPile / 2;
            sum -= removed;
            pq.push(maxPile - removed);
            k--;
        }

        return sum;
    }
};