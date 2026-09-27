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
class Node{
public:
    int min, max, sum;

    Node(int min, int max, int sum){
        this->min = min;
        this->max = max;
        this->sum = sum;
    }
};

class Solution {
public:
    int ans = 0;

    Node solve(TreeNode* root){
        if(root == NULL){
            return Node(INT_MAX, INT_MIN, 0);
        }

        auto left = solve(root->left);
        auto right = solve(root->right);

        if(left.max < root->val && right.min > root->val){
            int currMin = min(root->val, left.min);
            int currMax = max(root->val, right.max);
            int currSum = left.sum + right.sum + root->val;
            ans = max(ans, currSum);

            return Node(currMin, currMax, currSum);
        }
        
        return Node(INT_MIN, INT_MAX, 0);
    }

    int maxSumBST(TreeNode* root) {
        solve(root);

        return ans;
    }
};