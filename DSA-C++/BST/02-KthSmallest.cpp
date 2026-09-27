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
    // 1
    // void solveDFS(TreeNode* root, int k, vector<int>& ans){
    //     if(root == NULL){
    //         return;
    //     }

    //     ans.push_back(root->val);
    //     solveDFS(root->left, k, ans);
    //     solveDFS(root->right, k, ans);
    // }

    // 2
    // void inorder(TreeNode* root, vector<int>& ans){
    //     if(root == NULL){
    //         return;
    //     }

    //     inorder(root->left, ans);
    //     ans.push_back(root->val);
    //     inorder(root->right, ans);
    // }

    int kthSmallest(TreeNode* root, int k) {
        // APPROACH 1 (DFS)
        // TC -> O(n) + O(n log n)
        // SC -> O(n)
        // vector<int> ans;
        // solveDFS(root, k, ans);

        // sort(ans.begin(), ans.end());

        // return ans[k-1];

        // APPROACH 2 (Inorder -> left, root, right)
        // TC -> O(n)
        // SC -> O(n)

        // vector<int> ans;
        // inorder(root, ans);
        // return ans[k-1];


        // APPROACH 3 (Moris)
        // TC -> O(n)
        // SC -> O(1)

        TreeNode* curr = root;
        int ans = 0;
        int result = -1;

        while(curr != NULL){

            if(curr->left == NULL){
                ans++;
                if(ans == k){
                    result = curr->val;
                }
                curr = curr->right;
            }
            else{
                TreeNode* pre = curr->left;

                while(pre->right != NULL && pre->right != curr){
                    pre = pre->right;
                }

                if(pre->right == NULL){
                    pre->right = curr;
                    curr = curr->left;
                }
                else {
                    pre->right = NULL;

                    ans++;
                    if(ans == k){
                        result = curr->val;
                    }

                    curr = curr->right;
                }
            }
        }
        
        return result;
    }
};