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
    TreeNode* invertTree(TreeNode* root) {
        // APPROACH 1 (Recursive DFS)
        // TC -> O(n)
        // SC -> O(h)

        // if(root == NULL)
        //     return NULL;
        
        // // Two tricks to swap. 
        // // 1. swap function
        // // swap(root -> left, root -> right);

        // // 2. swap manually
        // TreeNode* temp = root -> left;
        // root -> left = root -> right;
        // root -> right = temp;

        // invertTree(root -> left);
        // invertTree(root -> right);

        // return root;

        // APPROACH 2 (Iterative BFS)
        // TC -> O(n)
        // SC -> O(w)

        // if(root == NULL)
        //     return NULL;
        
        // queue<TreeNode*> q;
        // q.push(root);

        // while(!q.empty()){

        //     TreeNode* temp = q.front();
        //     q.pop();

        //     swap(temp -> left, temp -> right);

        //     if(temp -> left)
        //         q.push(temp -> left);
        //     if(temp -> right)
        //         q.push(temp -> right);            
        // }
        // return root;

        // APPROACH 3 (Iterative DFS)
        // TC -> O(n)
        // SC -> O(h)

        if(root == NULL)
            return NULL;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){

            TreeNode* temp = st.top();
            st.pop();

            swap(temp -> left, temp -> right);

            if(temp -> left)
                st.push(temp -> left);
            if(temp -> right)
                st.push(temp -> right);
        }
        return root;
    }
};