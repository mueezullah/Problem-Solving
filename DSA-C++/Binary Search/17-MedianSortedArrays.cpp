class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // APPROACH 1 (Brute force)
        // TC -> O(m + n)
        // SC -> O(m + n)
        // int m = nums1.size();
        // int n = nums2.size();

        // vector<int> temp(m+n);

        // int i = 0;
        // int j = 0;
        // int k = 0;

        // while(i < m && j < n){
        //     if(nums1[i] <= nums2[j]){
        //         temp[k++] = nums1[i++];
        //     }
        //     else {
        //         temp[k++] = nums2[j++];
        //     }
        // }
        // while(i < m){
        //     temp[k++] = nums1[i++];
        // }
        // while(j < n){
        //     temp[k++] = nums2[j++];
        // }

        // int size = m + n;

        // if(size % 2 == 1){
        //     return temp[size / 2];
        // }
        // return (temp[size / 2] + temp[(size / 2) - 1]) / 2.0;

        // APPROACH 2 (Better)
        // TC -> O(m + n)
        // SC -> O(1)
        // int m = nums1.size();
        // int n = nums2.size();
        // int size = m + n;

        // int idx1 = (size / 2) - 1; 
        // int idx2 = size / 2;
        // int element1 = -1, element2 = -1;

        // int i = 0;
        // int j = 0;
        // int k = 0;

        // while(i < m && j < n){
        //     if(nums1[i] < nums2[j]){
        //         if(k == idx1){
        //             element1 = nums1[i];
        //         }
        //         if(k == idx2){
        //             element2 = nums1[i];
        //         }
        //         i++;
        //     }
        //     else {
        //         if(k == idx2){
        //             element2 = nums2[j];
        //         }
        //         if(k == idx1){
        //             element1 = nums2[j];
        //         }
        //         j++;
        //     }
        //     k++; // k will increase in both cases so we write it outside
        // }

        // while(i < m){
        //     if(k == idx1){
        //         element1 = nums1[i];
        //     }
        //     if(k == idx2){
        //         element2 = nums1[i];
        //     }
        //     i++;
        //     k++;
        // }
        // while(j < n){
        //     if(k == idx2){
        //         element2 = nums2[j];
        //     }
        //     if(k == idx1){
        //         element1 = nums2[j];
        //     }
        //     j++;
        //     k++;
        // }

        // if(size % 2 == 1){
        //     return element2;
        // }
        // return (element1 + element2) / 2.0;
        
        // APPROACH 3 (Binary Search) Optimal
        // TC -> O(log(min(m, n)))
        // SC -> O(1)

        int m = nums1.size();
        int n = nums2.size();

        if(m > n){
            return findMedianSortedArrays(nums2, nums1);
        }

        int start = 0, end = m;
        int totalElements = m + n;
        int left = (totalElements + 1) / 2;

        while(start <= end){
            int mid1 = start + (end - start) / 2; // mid1 == mid. mid1 from nums1
            int mid2 = left - mid1; // mid2 From nums2

            // Left Half | Right Half

            // Left Half elements
            int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];

            // RIght Half elements
            int r1 = (mid1 == m) ? INT_MAX : nums1[mid1];
            int r2 = (mid2 == n) ? INT_MAX : nums2[mid2];

            if(l1 <= r2 && l2 <= r1){

                if(totalElements % 2 == 1){
                    return max(l1, l2);
                }
                return ((double)max(l1, l2) + min(r1, r2)) / 2.0;
            }

            if(l1 > r2){
                end = mid1 - 1;
            }
            else {
                start = mid1 + 1;
            }
        }
        return -1;
    }
};