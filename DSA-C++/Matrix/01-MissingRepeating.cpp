class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // APPROACH 1 (Brute Force)
        int row = grid.size();
        int col = grid[0].size();
        // int totalElements = row * col;

        // vector<int> freq(totalElements + 1, 0);

        // for(int i = 0; i < row; i++){
        //     for(int j = 0; j < col; j++){
        //         freq[grid[i][j]]++;
        //     }
        // }

        // int repeated = -1, missing = -1;
        // for(int i = 1; i <= totalElements; i++){
        //     if(freq[i] == 0) missing = i;
        //     if(freq[i] == 2) repeated = i;
        // }
        // return {repeated, missing};

        // APPROACH 2 (Math)
        long long totalNumbers = 1LL * row * col;

        long long expectedSum = totalNumbers * (totalNumbers + 1) / 2;
        long long expectedSqSum = totalNumbers * (totalNumbers + 1) * (2 * totalNumbers + 1) / 6;

        long long actualSum = 0, actualSqSum = 0;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                actualSum += grid[i][j];
                actualSqSum += 1LL *grid[i][j] * grid[i][j];
            }
        }

        long long diffSum = actualSum - expectedSum;
        long long diffSqSum = actualSqSum - expectedSqSum; 

        long long sumRepeatedMissing = diffSqSum / diffSum;

        long long repeated = (diffSum + sumRepeatedMissing) / 2;
        long long missing = repeated - diffSum;

        return {(int)repeated, (int)missing};
    }
};