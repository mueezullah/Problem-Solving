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
    int minDepth(TreeNode* root) {
        // APPROACH 1 (Recursive DFS)
        // TC -> O(n)
        // SC -> O(h) max height

        // if(root == NULL)
        //     return 0;

        // if(root -> left == NULL && root -> right == NULL)
        //     return 1;

        // int left = INT_MAX, right = INT_MAX;

        // if(root -> left)
        //     left = minDepth(root -> left);
        
        // if(root -> right)
        //     right = minDepth(root -> right);

        // return min(left, right) + 1;


        // APPROACH 2 (Iterative BFS)
        // TC -> O(n)
        // SC -> O(w) max width

        if(root == NULL)
            return 0;

        queue<TreeNode*> q;
        q.push(root);

        int depth = 1;

        while(!q.empty()){

            int size = q.size();

            for(int i = 0; i < size; i++){

                TreeNode* temp = q.front();
                q.pop();

                if(temp -> left == NULL && temp -> right == NULL)
                    return depth;
                
                if(temp -> left)
                    q.push(temp -> left);
                if(temp -> right)
                    q.push(temp -> right);
            }

            depth++;
        }

        return -1;
    }
};