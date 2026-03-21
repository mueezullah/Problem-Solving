/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peakIdxInMountainArr(MountainArray &mountainArr){
        int n = mountainArr.length();
        int start = 0, end = n - 1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(mountainArr.get(mid) > mountainArr.get(mid + 1)){
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return start;
    }

    // ascending order
    int binarySearch(MountainArray &mountainArr, int start, int end, int target){
        
        while(start <= end){
            int mid = start + (end - start) / 2;

            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) > target){
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return -1;
    }

    // descending order
    int reverseBinarySearch(MountainArray &mountainArr, int start, int end, int target){

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) > target){
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // APPROACH 1 (Linear Search) Exceeds call limit
        // TC -> O(N)
        // SC -> O(1)
        // int n = mountainArr.length();
        
        // for(int i = 0; i < n; i++){
        //     if(mountainArr.get(i) == target){
        //         return i;
        //     }
        // }
        // return -1;

        // APPROACH 2 (Binary Search)
        // TC -> O(log N)
        // SC -> O(1)

        int n = mountainArr.length();
        int idx = peakIdxInMountainArr(mountainArr);

        // 0 to idx -> BS
        int resultIdx = binarySearch(mountainArr, 0, idx, target);

        if(resultIdx != -1){
            return resultIdx;
        }
        
        // idx + 1 to n - 1
        resultIdx = reverseBinarySearch(mountainArr, idx+1, n-1, target);

        return resultIdx;
    }
};