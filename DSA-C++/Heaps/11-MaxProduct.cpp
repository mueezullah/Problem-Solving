class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // APPROACH 1 (sort)
        // TC -> O(n log n)
        // SC -> O(1)
        // int n = nums.size();
        // int ans = 0;

        // if(n == 2){
        //     ans = (nums[0] - 1) * (nums[1] - 1);
        //     return ans;
        // }

        // sort(nums.begin(), nums.end());

        // return (nums[n-1] - 1) * (nums[n-2] - 1);


        // APPROACH 2 (Heap)
        // TC -> O(n log k) k = 2
        // SC -> O(1)

        int n = nums.size();

        if(n == 2){
            return (nums[0] - 1) * (nums[1] - 1);
        }

        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i : nums){
            pq.push(i);

            if(pq.size() > 2){
                pq.pop();
            }
        }

        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        ans = (a - 1) * (b - 1);
        return ans;
    }
};