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
    int solveDFS(TreeNode* root, int& maxSum){
        if(root == NULL){
            return 0;
        }

        int left = solveDFS(root->left, maxSum);
        int right = solveDFS(root->right, maxSum);

        int bendPath = left + right + root->val;

        int straightPath = max(left, right) + root->val;
        
        int rootValue = root->val;

        maxSum = max({maxSum, bendPath, straightPath, rootValue});

        return max(straightPath, rootValue);
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;

        solveDFS(root, maxSum);

        return maxSum;
    }
};