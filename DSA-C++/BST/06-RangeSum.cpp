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
    int rangeSumBST(TreeNode* root, int low, int high) {
        // APPROACH 1 (Naive)
        // TC -> O(N)
        // SC -> O(H)
        // if(root == NULL){
        //     return 0;
        // }

        // int sum = 0;
        // if(root->val >= low && root->val <= high){
        //     sum += root->val;
        // }

        // sum += rangeSumBST(root->left, low, high);
        // sum += rangeSumBST(root->right, low, high);

        // return sum;

        // APPROACH 2 (Optimal)
        // TC -> O(H + K)
        // SC -> O(H)

        if(root == NULL){
            return 0;
        }
        int sum = 0;

        if(root->val < low){
            return rangeSumBST(root->right, low, high);
        }
        if(root->val > high){
            return rangeSumBST(root->left, low, high);
        }

        return root->val 
            + rangeSumBST(root->left, low, high)
            + rangeSumBST(root->right, low, high);
    }
};