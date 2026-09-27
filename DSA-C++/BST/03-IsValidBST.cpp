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
    // void inorder(TreeNode* root, vector<int>& ans){
    //     if(root == NULL){
    //         return;
    //     }

    //     inorder(root->left, ans);
    //     ans.push_back(root->val);
    //     inorder(root->right, ans);
    // }

    bool solveOpt(TreeNode* root, long long lowerBound, long long higherBound){
        if(root == NULL){
            return true;
        }

        if(root->val <= lowerBound || root->val >= higherBound){
            return false;
        }

        bool left = solveOpt(root->left, lowerBound, root->val);
        bool right = solveOpt(root->right, root->val, higherBound);

        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        // APPROACH 1
        // TC -> O(n)
        // SC -> O(n)
        // vector<int> ans;
        // inorder(root, ans);

        // for(int i = 1; i < ans.size(); i++){
        //     if(ans[i] <= ans[i-1]){
        //         return false;
        //     }
        // }
        // return true;

        // APPROACH 2
        // TC -> O(n)
        // SC -> O(h)

        return solveOpt(root, LLONG_MIN, LLONG_MAX);
    }
};