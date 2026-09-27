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
    // bool solve(TreeNode* root, int k, unordered_set<int>& seen){
    //     if(root == NULL){
    //         return false;
    //     }

    //     int sum = k - root->val;

    //     if(seen.count(sum)){
    //         return true;
    //     }

    //     seen.insert(root->val);

    //     bool left = solve(root->left, k, seen);
    //     bool right = solve(root->right, k, seen);

    //     return left || right;
    // }

    void inorder(TreeNode* root, int k, vector<int>& in){
        if(root == NULL){
            return ;
        }

        inorder(root->left, k, in);
        in.push_back(root->val);
        inorder(root->right, k, in);
    }

    bool findTarget(TreeNode* root, int k) {
        // APPROACH 1
        // TC -> O(n)
        // SC -> O(n)
        // unordered_set<int> seen;

        // return solve(root, k, seen);

        // APPROACH 2
        // TC -> O(n)
        // SC -> O(n)

        vector<int> inorderElems;
        inorder(root, k, inorderElems);

        int start = 0, end = inorderElems.size() - 1;

        while(start < end){
            int sum = inorderElems[start] + inorderElems[end];

            if(sum == k){
                return true;
            }
            else if(sum > k){
                end--;
            }
            else{
                start++;
            }
        }
        
        return false;
    }
};