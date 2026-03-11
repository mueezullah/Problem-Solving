class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // APPROACH 1 (Brute Force)
        // TC -> O(rows * cols)
        // SC -> O(1)
        // int rows = matrix.size();
        // int cols = matrix[0].size();

        // for(int i = 0; i < rows; i++){
        //     for(int j = 0; j < cols; j++){
        //         if(matrix[i][j] == target){
        //             return true;
        //         }
        //     }
        // }
        // return false;

        // APPROACH 2 (Binary search on Each Row)
        // TC -> O(n log(m))
        // SC -> O(1)
        // int rows = matrix.size();
        // int cols = matrix[0].size();

        // for(int i = 0; i < rows; i++){
                
        //     int start = 0;
        //     int end = cols - 1;

        //     while(start <= end){
        //         int mid = start + (end - start) / 2;

        //         if(matrix[i][mid] == target){
        //             return true;
        //         }
        //         else if(matrix[i][mid] > target){
        //             end = mid - 1;
        //         }
        //         else {
        //             start = mid + 1;
        //         }
        //     }
        // }
        // return false;

        // APPROACH 3 (Binary Search Optimized)
        // TC -> O(n + m)
        // SC -> O(1)

        int rows = matrix.size();
        int cols = matrix[0].size();

        int row = 0, col = cols - 1;

        while(row < rows && col >= 0){
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] > target){
                col--; // move left
            }
            else {
                row++; // move down
            }
        }
        return false;
    }
};