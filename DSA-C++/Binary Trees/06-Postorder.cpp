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
    // POSTORDER rule -> Left -> Right -> Root

    // void postorder(TreeNode* root, vector<int>& ans){
    //     if(root == nullptr){
    //         return;
    //     }

    //     postorder(root -> left, ans);
    //     postorder(root -> right, ans);
    //     ans.push_back(root -> val);
    // }

    vector<int> postorderTraversal(TreeNode* root) {
        // APPROACH 1 (Reucrsive)
        // TC -> O(n)
        // SC -> O(n)

        // vector<int> ans;
        // postorder(root, ans);
        // return ans;

        // APPROACH 2 (Iterative + 2 Stacks)
        // TC -> O(n)
        // SC -> O(n)

        // vector<int> ans;
        // if(root == NULL) return ans;

        // stack<TreeNode*> st1, st2;
        // st1.push(root);

        // while(!st1.empty()){
        //     TreeNode* temp = st1.top();
        //     st1.pop();
        //     st2.push(temp);

        //     if(temp -> left) st1.push(temp -> left);
        //     if(temp -> right) st1.push(temp -> right);
        // }

        // while(!st2.empty()){
        //     ans.push_back(st2.top() -> val);
        //     st2.pop();
        // }

        // return ans;

        // APPROACH 3 (Iterative + 1 Stack)
        // TC -> O(n)
        // SC -> O(n)

        vector<int> ans;
        if(root == NULL) return ans;

        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp -> val);

            if(temp -> left) st.push(temp -> left);
            if(temp -> right) st.push(temp -> right);
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};