class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // APPROACH 1 (Brute force)
        // TC -> O(row * col)
        // SC -> O(1)
        // int row = matrix.size();
        // int col = matrix[0].size();

        // for(int i = 0; i < row; i++){
        //     for(int j = 0; j < col; j++){
        //         if(matrix[i][j] == target){
        //             return true;
        //         }
        //     }
        // }
        // return false;

        // APPROACH 2 (Row-wise binary search)
        // TC -> O(row log(col))
        // SC -> O(1)
        // int row = matrix.size();
        // int col = matrix[0].size();

        // for(int i = 0; i < row; i++){
        //     if(matrix[i][0] <= target && target <= matrix[i][col - 1]){
            
        //         int start = 0;
        //         int end = col - 1;

        //         while(start <= end) {
        //             int mid = start + (end - start) / 2;

        //             if(matrix[i][mid] == target)
        //                 return true;
        //             else if(matrix[i][mid] < target)
        //                 start = mid + 1;
        //             else
        //                 end = mid - 1;
        //         }
        //         return false;
        //     }
        // }
        // return false;

        // APPROACH 3 (Flattened binary search)
        // TC -> O(log(totalRows * totalCols))
        // SC -> O(1)
        int totalRows = matrix.size();
        int totalCols = matrix[0].size();

        int start = 0, end = totalRows * totalCols -1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            int row = mid / totalCols;
            int col = mid % totalCols;

            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] < target){
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return false;
    }
};