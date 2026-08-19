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
    int maxDepth(TreeNode* root) {
        // APPROACH 1 (Recursive DFS)
        // TC -> O(n)
        // SC -> O(h) -> height of tree

        // if(root == NULL)
        //     return 0;
        
        // if(root -> left == NULL && root -> right == NULL)
        //     return 1;

        // int left = INT_MIN, right = INT_MIN;

        // if(root -> left)
        //     left = maxDepth(root -> left);
        // if(root -> right)
        //     right = maxDepth(root -> right);

        // return 1 + max(left, right);


        // APPROACH 2 (Iterative BFS)
        // TC -> O(n)
        // SC -> O(w) -> width of tree

        if(root == NULL)
            return 0;
        
        queue<TreeNode*> q;
        q.push(root);

        int maxDepth = 0;

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front();
                q.pop();

                if(temp -> left)
                    q.push(temp -> left);
                if(temp -> right)
                    q.push(temp -> right);
                
            }
            maxDepth++;
        }

        return maxDepth;
    }
};