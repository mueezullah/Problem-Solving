class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // APPROACH 1 (Linear scan)
        // TC-> O(n)
        // SC-> O(1)

        // for(int i = 0; i < arr.size(); i++){
        //     if(arr[i] - (i+1) < k){
        //         continue;
        //     }
        //     else {
        //         return i + k;
        //     }
        // }
        // return arr.size() + k;

        // APPROACH 2 (Binary Scan)
        // TC-> O(log n)
        // SC-> O(1)

        int n = arr.size();
        int start = 0, end = n - 1;

        while(start <= end){

            int mid = start + (end - start) / 2;
            int missing = arr[mid] - (mid + 1);
            
            if(missing < k){
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return end + 1 + k; // return start + k;
    }
};