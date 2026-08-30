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
    // TreeNode* solve(vector<int>& preorder, vector<int>& postorder, 
    //     int postStart, int postEnd, int& preIdx){

    //     if(postStart > postEnd){
    //         return NULL;
    //     }
        
    //     int rootVal = preorder[preIdx];
    //     preIdx++;

    //     TreeNode* root = new TreeNode(rootVal);

    //     if(postStart == postEnd){
    //         return root;
    //     }

    //     int leftRootVal = preorder[preIdx];

    //     int i = postStart;
    //     for(; i <= postEnd; i++){
    //         if(postorder[i] == leftRootVal){
    //             break;
    //         }
    //     }

    //     root->left = solve(preorder, postorder, postStart, i, preIdx);
    //     root->right = solve(preorder, postorder, i + 1, postEnd - 1, preIdx);

    //     return root;
    // }

    TreeNode* optSolve(vector<int>& preorder, vector<int>& postorder, int postStart,
        int postEnd, int& preIdx, unordered_map<int, int>& mp){
        
        if(postStart > postEnd){
            return NULL;
        }

        int rootVal = preorder[preIdx];
        preIdx++;

        TreeNode* root = new TreeNode(rootVal);

        if(postStart == postEnd){
            return root;
        }

        int leftRootVal = preorder[preIdx];
        int i = mp[leftRootVal];

        root->left = optSolve(preorder, postorder, postStart, i, preIdx, mp);
        root->right = optSolve(preorder, postorder, i + 1, postEnd - 1, preIdx, mp);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        // APPROACH 1
        // TC -> O(n^2)
        // SC -> O(n)
        // int n = preorder.size();
        // int preIdx = 0;

        // return solve(preorder, postorder, 0, n - 1, preIdx);

        // APPROACH 2
        // TC -> O(n)
        // SC -> O(n)

        unordered_map<int, int> mp;
        int n = preorder.size();
        int preIdx = 0;

        for(int i = 0; i < n; i++){
            mp[postorder[i]] = i;
        }

        return optSolve(preorder, postorder, 0, n - 1, preIdx, mp);
    }
};