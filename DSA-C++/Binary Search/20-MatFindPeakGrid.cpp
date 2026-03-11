class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // APPROACH 1 (Brute Force)
        // TC -> O(m * n)
        // SC -> O(1)
        // int rows = mat.size();
        // int cols = mat[0].size();

        // for(int r = 0; r < rows; r++){
        //     for(int c = 0; c < cols; c++){
                
        //         int current = mat[r][c];
                
        //         bool up = (r == 0) || (current > mat[r - 1][c]);
        //         bool down = (r == rows - 1) || (current > mat[r + 1][c]);
        //         bool left = (c == 0) || (current > mat[r][c - 1]);
        //         bool right = (c == cols - 1) || (current > mat[r][c + 1]);

        //         if(up && down && left && right){
        //             return {r, c};
        //         }
        //     }
        // }
        // return {-1, -1};

        // APPROACH 2 ()
        // TC -> O(m log n)
        // SC -> O(1)
        int rows = mat.size();
        int cols = mat[0].size();

        int start = 0, end = cols - 1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            // finding maximum row in this column
            int maxRow = 0;

            for(int r = 0; r < rows; r++){
                if(mat[r][mid] > mat[maxRow][mid]){
                    maxRow = r;
                }
            }

            int left  = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;
            int right = (mid + 1 < cols) ? mat[maxRow][mid + 1] : -1;

            // check if peak
            if(mat[maxRow][mid] > left && mat[maxRow][mid] > right){
                return {maxRow, mid};
            }
            else if(left > mat[maxRow][mid]){
                end = mid - 1; // move left
            }
            else{
                start = mid + 1; // move right
            }
        }
        return {-1, -1};
    }
};