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
    int solve(TreeNode* root, int& sum, string& number){
        if(root == NULL){
            return sum;
        }

        number += to_string(root -> val);

        if(root -> left == NULL && root -> right == NULL){
            sum += stoi(number);
        }

        solve(root -> left, sum, number);
        solve(root -> right, sum, number);

        number.pop_back();

        return sum;
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        string number = "";

        return solve(root, sum, number);
    }
};