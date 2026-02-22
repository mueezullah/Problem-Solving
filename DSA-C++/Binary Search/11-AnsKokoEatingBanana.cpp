class Solution {
public:
    bool canEatBanana(vector<int>& piles, int h, int mid){
        long long actualHours = 0;
        for(int x : piles){
            actualHours += x/mid;   // if h = 3, and pile is 7 -> 7/3 = 2

            if(x % mid != 0){// 7 % 2 = 1 because for 7 -> 2hrs = 3,3 and 1hr = 1
                actualHours++;
            }
        }
        return actualHours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int start = 1, end = *max_element(piles.begin(), piles.end());
        int ans = end;

        while(start <= end){
            int mid = start + (end - start) / 2; // koko's eating speed

            if(canEatBanana(piles, h, mid)){
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return ans;
    }
};