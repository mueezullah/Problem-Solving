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
    // INORDER rule -> Left -> Root -> Right


    // void inorder(TreeNode* root, vector<int>& ans){
    //     if(root == nullptr){
    //         return;
    //     }

    //     inorder(root -> left, ans);
    //     ans.push_back(root -> val);
    //     inorder(root -> right, ans);
    // }

    vector<int> inorderTraversal(TreeNode* root) {
        // APPROACH 1 (Recursive)
        // TC -> O(n)
        // SC -> O(n)

        // vector<int> ans;
        // inorder(root, ans);
        // return ans;

        // APPROACH 2 (Iterative)
        // TC -> O(n)
        // SC -> O(n)

        // vector<int> ans;
        // if(root == nullptr) return ans;

        // stack<TreeNode*> st;
        // TreeNode* temp = root;

        // while(temp != NULL || !st.empty()){

        //     while(temp != NULL){
        //         st.push(temp);
        //         temp = temp -> left;
        //     }

        //     temp = st.top();
        //     st.pop();

        //     ans.push_back(temp -> val);

        //     temp = temp -> right;
        // }

        // return ans;


        // APPROACH 3 (Morris)
        // TC -> O(n)
        // SC -> O(1)

        vector<int> ans;
        TreeNode* curr = root;

        while(curr != NULL){

            if(curr -> left == NULL){
                ans.push_back(curr -> val);
                curr = curr -> right;
            } else {
                TreeNode* pre = curr -> left;
                while(pre -> right != NULL && pre -> right != curr){
                    pre = pre -> right;
                }

                if(pre -> right == NULL){
                    pre -> right = curr;
                    curr = curr -> left;
                }
                else {
                    ans.push_back(curr -> val);
                    pre -> right = NULL;
                    curr = curr -> right;
                }
            }
        }

        return ans;
    }
};