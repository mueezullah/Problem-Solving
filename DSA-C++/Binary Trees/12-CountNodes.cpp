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
    // int countAll(TreeNode* root, int count){
    //     if(root == NULL)
    //         return count;
        
    //     int countL = countAll(root -> left, count);
    //     int countR = countAll(root -> right, count);

    //     return 1 + (countL + countR);
    // }

    int countNodes(TreeNode* root) {
        // APPROACH 1 (Recursive DFS)
        // TC -> O(n)
        // SC -> O(h)

        // return countAll(root, 0);

        // APPROACH 2 (Iterative BFS)
        // TC -> O(n)
        // SC -> O(w)

        if(root == NULL)
            return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int count = 1;

        while(!q.empty()){
            
            TreeNode* temp = q.front();
            q.pop();

            if(temp -> left){
                q.push(temp -> left);
                count++;
            }

            if(temp -> right){
                q.push(temp -> right);
                count++;
            }   
        }

        return count;
    }
};