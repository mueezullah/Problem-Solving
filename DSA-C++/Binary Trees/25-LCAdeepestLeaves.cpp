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
    // unordered_map<int, int> mp;
    // int maxD = 0;

    // void findDepth(TreeNode* root, int d){
    //     if(root == NULL){
    //         return;
    //     }

    //     mp[root->val] = d;
    //     maxD = max(maxD, d);

    //     findDepth(root->left,  d + 1);
    //     findDepth(root->right, d + 1);
    // }

    // TreeNode* LCA(TreeNode* root){
    //     if(root == NULL){
    //         return NULL;
    //     }

    //     if(mp[root->val] == maxD){
    //         return root;
    //     }

    //     TreeNode* left  = LCA(root->left);
    //     TreeNode* right = LCA(root->right);

    //     if(left != NULL && right != NULL){
    //         return root;
    //     }

    //     return left ? left : right;
    // }

    pair<int, TreeNode*> solve(TreeNode* root){
        if(root == NULL){
            return {0, NULL};
        }

        auto left  = solve(root->left);
        auto right = solve(root->right);

        if(left.first == right.first){
            return {left.first + 1, root};
        }
        else if(right.first > left.first){
            return {right.first + 1, right.second};
        }
        else {
            return {left.first + 1, left.second};
        }
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        // APPROACH 1 (DFS) 2-Pass
        // TC -> O(n + n) -> O(2n) -> o(n)
        // SC -> O(maxD)
        // findDepth(root, 0);

        // return LCA(root);

        // APPROACH 2 (DFS) 1-Pass
        // TC -> O(n)
        // SC -> O(height)

        return solve(root).second;
    }
};