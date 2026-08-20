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
    // bool solveRec(TreeNode* left, TreeNode* right){
    //     if(left == NULL && right == NULL)
    //         return true;

    //     if(left == NULL || right == NULL)
    //         return false;
        
    //     if(left -> val != right -> val)
    //         return false;

    //     bool first = solveRec(left -> left, right -> right);
    //     bool second = solveRec(left -> right, right -> left);

    //     return first && second;
    // }

    bool isSymmetric(TreeNode* root) {
        // APPROACH 1 (Recursive DFS)
        // TC -> O(n)
        // SC -> O(h)
        
        // bool ans = solveRec(root -> left, root -> right);
        // return ans;

        // APPROACH 2 (Iterative BFS)
        // TC -> O(n)
        // SC -> O(w)

        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root -> left, root -> right});

        while(!q.empty()){

            auto [left, right] = q.front();
            q.pop();

            if(left == NULL && right == NULL)
                continue;

            if(left == NULL || right == NULL)
                return false;

            if(left -> val != right -> val){
                return false;
            }

            q.push({left -> left, right -> right});
            q.push({left -> right, right -> left});

        }
        return true;
    }
};