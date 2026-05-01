class Solution {
public:
    // TC -> O(N * M * 4^L)
    // SC -> O(L) word length
    bool solve(vector<vector<char>>& board, int i, int j, int n,
        int m, int idx, string& word){
        
        if(idx == word.length())
            return true;
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '$')
            return false;
        if(board[i][j] != word[idx]) return false;

        char temp = board[i][j];
        board[i][j] = '$';

        // explore all four directions 1st way
        // int x[4] = {0, 0, 1, -1};
        // int y[4] = {1, -1, 0, 0};

        // for(int dir = 0; dir < 4; dir++){
        //     int new_i = i + x[dir];
        //     int new_j = j + y[dir];

        //     if(solve(board, new_i, new_j, n, m, idx + 1, word)){
        //         return true;
        //     }
        // }

        // explore all four directions 2nd way
        bool found = solve(board, i+1, j, n, m, idx + 1, word) ||
                     solve(board, i-1, j, n, m, idx + 1, word) ||
                     solve(board, i, j+1, n, m, idx + 1, word) ||
                     solve(board, i, j-1, n, m, idx + 1, word);

        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]){
                    if(solve(board, i, j, n, m, 0, word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};