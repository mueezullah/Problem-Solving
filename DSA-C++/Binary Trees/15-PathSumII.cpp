/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> solve(TreeNode* root, int targetSum, int sum,
                            vector<vector<int>>& ans, vector<int>& path){

        if(root == NULL)
            return ans;

        sum += root -> val;
        path.push_back(root -> val);

        if(root -> left == NULL && root -> right == NULL){
            if(targetSum == sum){
                ans.push_back(path);
            }
        }

        solve(root -> left, targetSum, sum, ans, path);
        solve(root -> right, targetSum, sum, ans, path);

        path.pop_back();

        return ans;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;

        if(root == NULL)    
            return ans;
        
        int sum = 0;

        ans = solve(root, targetSum, sum, ans, path);
        return ans;
    }
};