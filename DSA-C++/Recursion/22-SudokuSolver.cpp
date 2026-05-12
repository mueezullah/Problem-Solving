class Solution {
public:
    // TC -> O(9 ^ (empty cells))
    // SC -> O(1)
    bool isValid(vector<vector<char>>& board, int row, int col, char val){
        
        // scan row
        for(int i = 0; i < 9; i++){
            if(board[i][col] == val){
                return false;
            }
        }
        // scan col
        for(int i = 0; i < 9; i++){
            if(board[row][i] == val){
                return false;
            }
        }
            
        // scan 3x3 box
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for(int dr = 0; dr < 3; dr++){ // delta row = dr
            for(int dc = 0; dc < 3; dc++){ // delta col = dc

                if(board[startRow + dr][startCol + dc] == val){
                    return false;
                }
            }
        }
        
        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){

                if(board[i][j] == '.'){
                    
                    for(char ch = '1'; ch <= '9'; ch++){
                        if(isValid(board, i, j, ch)){
                            
                            board[i][j] = ch;
                            if(solve(board) == true){
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;

    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};