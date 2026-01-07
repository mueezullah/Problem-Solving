class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Appraoch 1 (Brute Force)
        // copy nums2 into nums1
        // for(int i = 0; i < n; i++){
        //     nums1[m+i] = nums2[i];
        // }
        // // sort nums1 because all element of nums2 are now in nums1
        // sort(nums1.begin(), nums1.end());
        
        // APPROACH 2 (Two Pointer + Extra space)
        // vector<int> ans;
        // int i = 0, j = 0;
        
        // while(i < m && j < n){
        //     if(nums1[i] <= nums2[j]){
        //         ans.push_back(nums1[i]);
        //         i++;
        //     } 
        //     else {
        //         ans.push_back(nums2[j]);
        //         j++;
        //     }
        // }

        // while(i < m){
        //     ans.push_back(nums1[i]);
        //     i++;
        // }
        // while(j < n){
        //     ans.push_back(nums2[j]);
        //     j++;
        // }

        // for(int k = 0; k < m+n; k++){
        //     nums1[k] = ans[k];
        // }

        // APPROACH 3 (Two Pointer -> Reverse)

        int i = m-1;
        int j = n-1;
        int k = m+n - 1;

        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            }
            else{
                nums1[k--] = nums2[j--];
            }
        }

        while(j >= 0){
            nums1[k--] = nums2[j--];
        }
    }
};