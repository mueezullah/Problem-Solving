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
    // void DFS(TreeNode* root, int level, vector<int>& ans){
    //     if(root == NULL)
    //         return;
        
    //     if(ans.size() < level){
    //         ans.push_back(root->val);
    //     }

    //     DFS(root->right, level + 1, ans);
    //     DFS(root->left, level + 1, ans);
    // }

    vector<int> rightSideView(TreeNode* root) {
        // APPROACH 1 (DFS)
        // TC -> O(n)
        // SC -> O(h)

        // vector<int> ans;

        // DFS(root, 1, ans);

        // return ans;

        // APPROACH 2 (BFS)
        // TC -> O(n)
        // SC -> O(w)
        
        vector<int> ans;

        if(root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int n = q.size();

            for(int i = 0; i < n; i++){

                TreeNode* temp = q.front();
                q.pop();
                
                if(i == 0){
                    ans.push_back(temp->val);
                }
                if(temp->right)
                    q.push(temp->right);
                if(temp->left)
                    q.push(temp->left);
            }
        }
        return ans;
    }
};