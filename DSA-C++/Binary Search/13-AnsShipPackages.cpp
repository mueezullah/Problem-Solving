class Solution {
public:
    // TC -> O(n log(sum - max))
    // SC -> O(1)
    int reqDays(vector<int>& weights, int capacity, int n){
        int days = 1, load = 0;
        for(int i = 0; i < n; i++){
            if(weights[i] + load > capacity){
                load = weights[i];
                days++;
            }
            else {
                load += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        
        int start = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);
        int ans = -1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            int numberOfDays = reqDays(weights, mid, n);
            if(numberOfDays <= days){
                ans = mid;
                end = mid - 1; // try smaller capacity
            }
            else {
                start = mid + 1; // increase capacity
            }
        }
        return ans;
    }
};