class Solution {
public:
    
    void reverseArray(vector<int>& arr, int start, int end){
        while(start < end){
            swap(arr[start++], arr[end--]);
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        // APPROACH 1 (Extra Space)
        // vector<int> temp(n);

        // for(int i = 0; i < n; i++){
        //     temp[(i+k) % n] = nums[i];
        // }

        // nums = temp;

        // APPROACH 2 (Using Helper function)
        // k = k % n;
        
        // func calls
        // reverseArray(nums, 0, n-1);   // Reverse entire array
        // reverseArray(nums, 0, k-1);   // Reverse first k elements
        // reverseArray(nums, k, n-1);   // Reverse remaining elements

        // APPROACH 3 (Using STL reverse())
        k = k % n; // Ensure k is within the range of [0-n]
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};