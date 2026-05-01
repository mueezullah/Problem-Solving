// class Solution {
// public:
//     // APPROACH 1
//     // TC -> O(N!)
//     // SC -> O(N)
//     bool isValid(vector<string>& board, int n, int row, int col){
        
//         // Look Upward
//         int i = row - 1;
//         while(i >= 0){
//             if(board[i][col] == 'Q'){
//                 return false;
//             }
//             i--;
//         }

//         // check Left diagonal upward
//         i = row - 1;
//         int j = col - 1;
//         while(i >= 0 && j >= 0){
//             if(board[i][j] == 'Q'){
//                 return false;
//             }
//             i--;
//             j--;
//         }

//         // check right diagonal upward
//         i = row - 1;
//         j = col + 1;
//         while(i >= 0 && j < n){
//             if(board[i][j] == 'Q'){
//                 return false;
//             }
//             i--;
//             j++;
//         }
//         return true;
//     }
    
//     void solve(int n, int row, vector<string>& board, vector<vector<string>>& result){

//         if(row == n){
//             result.push_back(board);
//             return;
//         }

//         for(int col = 0; col < board.size(); col++){

//             if(isValid(board, n, row, col)){

//                 board[row][col] = 'Q';
//                 solve(n, row + 1, board, result);
//                 board[row][col] = '.';

//             }
//         }
//     }
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> result;

//         vector<string> board(n, string(n, '.'));

//         solve(n, 0, board, result); // row = 0
//         return result;
//     }
// };


// APPROACH 2
// TC -> O(N!)
// SC -> O(N)
class Solution {
public:

    void solve(vector<vector<string>>& result, vector<string>& board, 
                int row, int n, 
                unordered_set<int>& cols,
                unordered_set<int>& posDiag,
                unordered_set<int>& negDiag){
        
        if(row == n){
            result.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++){

            int pos = row + col;
            int neg = row - col;

            if(cols.find(col) != cols.end() ||
               posDiag.find(pos) != posDiag.end() ||
               negDiag.find(neg) != negDiag.end()){
                
                continue;
            }

            // for given [row][col] = 'Q'
            cols.insert(col);
            posDiag.insert(pos);
            negDiag.insert(neg);
            board[row][col] = 'Q';

            solve(result, board, row+1, n, cols, posDiag, negDiag);

            cols.erase(col);
            posDiag.erase(pos);
            negDiag.erase(neg);
            board[row][col] = '.';

        }
    }


    vector<vector<string>> solveNQueens(int n){

        vector<vector<string>> result;
        vector<string> board(n, string(n, '.')); // n = 3 ->> {"...", "...", "..."}

        unordered_set<int> cols;
        unordered_set<int> posDiag;
        unordered_set<int> negDiag;


        solve(result, board, 0, n, cols, posDiag, negDiag);
        return result;
    }
};
