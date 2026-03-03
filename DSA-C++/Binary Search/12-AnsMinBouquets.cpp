class Solution {
public:
    // TC -> O(n log (max Days))
    // SC -> o(1)
    int getBouquetCount(vector<int>& bloomDay, int mid, int k, int n){

        int bouquetCount = 0;
        int adjacentFlowers = 0;

        for(int i = 0; i < n; i++){
            if(bloomDay[i] <= mid){
                adjacentFlowers++;
            }
            else {
                adjacentFlowers = 0;
            }

            if(adjacentFlowers == k){
                bouquetCount++;
                adjacentFlowers = 0;
            }
        }
        return bouquetCount;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        int startDay = 1, endDay = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        
        if((long long)m * k > n) return -1;

        while(startDay <= endDay){
            int mid = startDay + (endDay - startDay) / 2;

            if(getBouquetCount(bloomDay, mid, k, n) >= m){
                ans = mid;
                endDay = mid - 1;
            }
            else {
                startDay = mid + 1;
            }
        }
        return ans;
    }
};