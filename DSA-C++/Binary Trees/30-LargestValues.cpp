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
    void DFS(TreeNode* root, int depth, vector<int>& ans){
        if(root == NULL){
            return;
        }

        if(ans.size() == depth){
            ans.push_back(root->val);
        }
        else {
            ans[depth] = max(ans[depth], root->val);
        }

        DFS(root->left, depth + 1, ans);
        DFS(root->right, depth + 1, ans);

    }

    vector<int> largestValues(TreeNode* root) {
        // APPROACH 1 (BFS)
        // TC -> O(n)
        // SC -> O(n)

        // vector<int> ans;

        // if(root == NULL){
        //     return {};
        // }

        // queue<TreeNode*> q;
        // q.push(root);

        // while(!q.empty()){
        //     int size = q.size();
        //     int maxi = INT_MIN;

        //     for(int i = 0; i < size; i++){
        //         TreeNode* temp = q.front();
        //         q.pop();

        //         maxi = max(maxi, temp->val);

        //         if(temp->left){
        //             q.push(temp->left);
        //         }
        //         if(temp->right){
        //             q.push(temp->right);
        //         }
        //     }

        //     ans.push_back(maxi);
        // }

        // return ans;

        // APPROACH 2 (DFS)
        // TC -> O(n)
        // SC -> O(h)

        vector<int> ans;
        DFS(root, 0, ans);
        
        return ans;
    }
};