class Solution {
public:
    int partition(vector<int>& nums, int left, int right){
        int pivot = nums[left];
        int i = left + 1;
        int j = right;

        while(i <= j){
            if(nums[i] < pivot && pivot < nums[j]){
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            if(nums[i] >= pivot){
                i++;
            }
            if(nums[j] <= pivot){
                j--;
            }
        }

        swap(nums[left], nums[j]);

        return j;
    }

    int findKthLargest(vector<int>& nums, int k) {
        // APPROACH 1 (sort)
        // TC -> O(n log n)
        // SC -> O(log n)

        // int n = nums.size();
        // sort(nums.begin(), nums.end());

        // return nums[n - k];

        // APPROACH 2 (Heap)
        // TC -> O(n log k)
        // SC -> O(k)

        // priority_queue<int, vector<int>, greater<int>> pq;

        // for(int num : nums){
            
        //     pq.push(num);

        //     if(pq.size() > k){
        //         pq.pop();
        //     }
        // }

        // return pq.top();

        // APPROACH 3 (Quick Sort)
        // TC -> O(n) avg. O(n^2) worst.
        // SC -> O(1)

        int left = 0, right = nums.size() - 1;

        while(true){
            int pivotIdx = partition(nums, left, right);

            if(pivotIdx == k - 1){
                return nums[pivotIdx];
            }

            if(pivotIdx < k - 1){
                left = pivotIdx + 1;
            }
            else {
                right = pivotIdx - 1;
            }
        }
        
        return -1;
    }
};