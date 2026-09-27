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
    // TreeNode* solve(TreeNode* root, int val){
    //     if(root == NULL){
    //         return new TreeNode(val);
    //     }

    //     if(root->val > val){
    //         root->left = solve(root->left, val);
    //     }
    //     else {
    //         root->right = solve(root->right, val);
    //     }

    //     return root;
    // }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // APPROACH 1 (DFS)
        // TC -> O(log n) balanced
        // SC -> O(log n) balanced
        // TC -> O(n) skewed
        // SC -> O(n) skewed

        // return solve(root, val);

        // APPROACH 2 (BFS)
        // TC -> O(log n) balanced
        // SC -> O(1) balanced
        // TC -> O(n) skewed
        // SC -> O(1) skewed

        if(root == NULL){
            return new TreeNode(val);
        }

        TreeNode* curr = root;
        bool flag = true;


        while(flag == true){
            if(curr->val < val){
                if(curr->right != NULL){
                    curr = curr->right;
                }
                else {
                    curr->right = new TreeNode(val);
                    flag = false;
                }
            }
            else {
                if(curr->left != NULL){
                    curr = curr->left;
                }
                else {
                    curr->left = new TreeNode(val);
                    flag = false;
                }
            }
        }

        return root;
    }
};