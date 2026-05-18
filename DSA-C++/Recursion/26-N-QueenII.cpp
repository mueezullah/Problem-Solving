// // APPROACH 1
// // TC -> O(N!)
// // SC -> O(N)

// class Solution {
// public:
//     bool isValid(vector<string>& board, int n, int row, int col){
//         // look up
//         int i = row - 1;
//         while(i >= 0){
//             if(board[i][col] == 'Q'){
//                 return false;
//             }
//             i--;
//         }

//         // check left diagonal upward
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

//     void solve(int n, int& count, vector<string>& board, int row){

//         if(row == n){
//             count++;
//             return;
//         }

//         for(int col = 0; col < n; col++){

//             if(isValid(board, n, row, col)){

//                 board[row][col] = 'Q';
//                 solve(n, count, board, row+1);
//                 board[row][col] = '.';
//             }
//         }
//     }

//     int totalNQueens(int n) {
        
//         int count = 0;
//         vector<string> board(n, string(n, '.'));

//         solve(n, count, board, 0);
//         return count;
//     }
// };

// APPROACH 2
// TC -> O(N!)
// SC -> O(N)

class Solution {
public:
    void solve(int n, int& count, int row,
                unordered_set<int>& cols,
                unordered_set<int>& posDiag,
                unordered_set<int>& negDiag){
        
        if(row == n){
            count++;
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

            cols.insert(col);
            posDiag.insert(pos);
            negDiag.insert(neg);

            solve(n, count, row+1, cols, posDiag, negDiag);

            cols.erase(col);
            posDiag.erase(pos);
            negDiag.erase(neg);
        }
    }

    int totalNQueens(int n){
        int count = 0;
        
        unordered_set<int> cols;
        unordered_set<int> posDiag;
        unordered_set<int> negDiag;

        solve(n, count, 0, cols, posDiag, negDiag);
        return count;
    }
};