/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // TreeNode* solveDFS(TreeNode* root, TreeNode* p, TreeNode* q){
    //     if(root == NULL){
    //         return NULL;
    //     }

    //     int curVal = root->val;

    //     if(curVal < p->val && curVal < q->val){
    //         return solveDFS(root->right, p, q);
    //     }
    //     else if(curVal > p->val && curVal > q->val){
    //         return solveDFS(root->left, p, q);
    //     }

    //     return root;
    // }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // APPROACH 1 (DFS)
        // TC -> O(h)
        // SC -> O(h)
        // TreeNode* ans;
        // ans = solveDFS(root, p, q);
        
        // return ans;

        // APPROACH 2 (Iterative)
        // TC -> O(h)
        // SC -> O(1)

        while(root != p || root != q){
            
            if(root->val < p->val && root->val < q->val){
                root = root->right;
            }
            else if(root->val > p->val && root->val > q->val){
                root = root->left;
            }
            else {
                return root;
            }
        }

        return NULL;
    }
};