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
    int solveDFS(TreeNode* root, int& maxDia){
        if(root == NULL){
            return 0;
        }

        int left = solveDFS(root->left, maxDia);
        int right = solveDFS(root->right, maxDia);
        
        // Diameter at this node
        int diaThroughRoot = (left + right);

        maxDia = max(maxDia, diaThroughRoot);

        // return height of this subtree
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;

        solveDFS(root, maxDia);

        return maxDia;
    }
};