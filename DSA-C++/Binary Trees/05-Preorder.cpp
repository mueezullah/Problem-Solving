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
    // PREORDER rule -> Root -> Left -> Right

    
    // void preorder(TreeNode* root, vector<int>& ans){
    //     if(root == nullptr){
    //         return;
    //     }

    //     ans.push_back(root -> val);

    //     preorder(root -> left, ans);
    //     preorder(root -> right, ans);
    // }

    vector<int> preorderTraversal(TreeNode* root) {
        // APPROACH 1 (Recursion)
        // TC -> O(n)
        // SC -> O(n)

        // vector<int> ans;
        // preorder(root, ans);
        // return ans;

        // APPROACH 2 (Iterative)
        // TC -> O(n)
        // SC -> O(n)

        // vector<int> preorder;
        // if(root == nullptr) return preorder;

        // stack<TreeNode*> st;
        // st.push(root);

        // while(!st.empty()){
        //     TreeNode* temp = st.top();
        //     st.pop();
        //     preorder.push_back(temp -> val);

        //     if(temp -> right) st.push(temp -> right);
        //     if(temp -> left) st.push(temp -> left);
        // }

        // return preorder;

        // APPROACH 3 (Morris)
        // TC -> O(n)
        // SC -> O(1)

        vector<int> ans;
        TreeNode* curr = root;

        while(curr != NULL){

            if(curr -> left == NULL){
                ans.push_back(curr -> val);
                curr = curr -> right;
            }
            else{
                TreeNode* pre = curr -> left;

                while(pre -> right != NULL && pre -> right != curr){
                    pre = pre -> right;
                }
                if(pre -> right == NULL){
                    ans.push_back(curr -> val);
                    pre -> right = curr;
                    curr = curr -> left;
                }
                else{
                    pre -> right = NULL;
                    curr = curr -> right;
                }
            }
        }
        return ans;
    }
};