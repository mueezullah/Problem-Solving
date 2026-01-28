class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // APPROACH 1 (Extra Space)
        int rows = matrix.size();
        int cols = matrix[0].size();
        // vector<pair<int, int>> zeroes;

        // for(int i = 0; i < rows; i++){
        //     for(int j = 0; j < cols; j++){
        //         if(matrix[i][j] == 0){
        //             zeroes.push_back({i, j});
        //         }
        //     }
        // }

        // for(auto [r, c] : zeroes){
        //     for(int i = 0; i < rows; i++){
        //         matrix[i][c] = 0;
        //     }

        //     for(int j = 0; j < cols; j++){
        //         matrix[r][j] = 0;
        //     }
        // }

        // APPROACH 2 (No extra space)
        bool firstRowZeroFlag = false, firstColZeroFlag = false;

        for(int i = 0; i < rows; i++){  // check first column
            if(matrix[i][0] == 0){
                firstColZeroFlag = true;
                break;
            }
        }
        for(int j = 0; j < cols; j++){  // check first row
            if(matrix[0][j] == 0){
                firstRowZeroFlag = true;
                break;
            }
        }
        for(int i = 1; i < rows; i++){  // mark rows and cols
            for(int j = 1; j < cols; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < rows; i++){  // apply markers
            for(int j = 1; j < cols; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstColZeroFlag == true){   // handle first col
            for(int i = 0; i < rows; i++){
                matrix[i][0] = 0;
            }
        }
        if(firstRowZeroFlag == true){   // handle first row
            for(int j = 0; j < cols; j++){
                matrix[0][j] = 0;
            }
        }
    }
};