class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        // APPROACH 1 (Extra space)
        // vector<vector<int>> ans(rows, vector<int> (cols, 0));

        // for(int i = 0; i < rows; i++){
        //     for(int j = 0; j < cols; j++){
        //         ans[j][rows-1-i] = matrix[i][j];
        //     }
        // }
        // matrix = ans;

        // APPROACH 2 (Transpose + Reverse)
        for(int i = 0; i < rows; i++){
            for(int j = i+1; j < cols; j++){
                swap(matrix[i][j],  matrix[j][i]);
            }
        }
        for(int i = 0; i < rows; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};