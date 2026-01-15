class Solution {
public:
    
    void reverseArray(vector<int>& arr, int start, int end){
        while(start < end){
            swap(arr[start++], arr[end--]);
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        // APPROACH 1
        // vector<int> temp(n);

        // for(int i = 0; i < n; i++){
        //     temp[(i+k) % n] = nums[i];
        // }

        // nums = temp;

        // APPROACH 2
        k = k % n;
        
        // func calls
        reverseArray(nums, 0, n-1);   // Reverse entire array
        reverseArray(nums, 0, k-1);   // Reverse first k elements
        reverseArray(nums, k, n-1);   // Reverse remaining elements

    }
};