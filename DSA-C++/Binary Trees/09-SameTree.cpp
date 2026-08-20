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
    // bool sameTreeRec(TreeNode* p, TreeNode* q){
    //     if(p == NULL && q == NULL)
    //         return true;
        
    //     if(p == NULL || q == NULL)
    //         return false;
        
    //     if(p -> val != q -> val)
    //         return false;

    //     bool left = sameTreeRec(p -> left, q -> left);
    //     bool right = sameTreeRec(p -> right, q -> right);

    //     return left && right;
    // }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        // APPROACH 1 (Recursive DFS)
        // TC -> O(n)
        // SC -> O(h)

        // return sameTreeRec(p, q);

        // APPROACH 2 (Iterative BFS)
        // TC -> O(n)
        // SC -> O(w)

        queue<pair<TreeNode*, TreeNode*>> qu;
        qu.push({p, q});

        while(!qu.empty()){
            auto [p, q] = qu.front();
            qu.pop();

            if(p == NULL && q == NULL)
                continue;
            
            if(p == NULL || q == NULL)
                return false;

            if(p -> val != q -> val)
                return false;
            
            qu.push({p -> left, q -> left});
            qu.push({p -> right, q -> right});
        }

        return true;
    }
};