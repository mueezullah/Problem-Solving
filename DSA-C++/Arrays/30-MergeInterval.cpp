class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // APPROACH 1
        // int n = intervals.size();
        // sort(intervals.begin(), intervals.end());
        // vector<vector<int>> ans;

        // for(int i = 0; i < n; i++){
        //     int firstElem = intervals[i][0];
        //     int secondElem = intervals[i][1];
        //     if(!ans.empty() && secondElem <= ans.back()[1]){
        //         continue;
        //     }
        //     for(int j = i+1; j < n; j++){
        //         if(intervals[j][0] <= secondElem){
        //             secondElem = max(secondElem, intervals[j][1]);
        //         }
        //         else {
        //             break;
        //         }
        //     }
        //     ans.push_back({firstElem, secondElem});
        // }
        // return ans;

        // APPROACH 2
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            if(ans.empty() || intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};