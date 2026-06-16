class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> helper(heights);

        sort(helper.begin(), helper.end());
        int count = 0;

        for(int i = 0; i < heights.size(); i++){
            if(heights[i] != helper[i]){
                count++;
            }
        }
        return count;
        
    }
};