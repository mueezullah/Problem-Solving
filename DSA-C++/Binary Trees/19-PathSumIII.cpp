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
    int solveDFS(TreeNode* root, int targetSum,
                unordered_map<long long, long long>& mp, int& ans,
                long long prefixSum){
        if(root == NULL){
            return 0;
        }

        prefixSum += root->val;

        if(mp.find(prefixSum - targetSum) != mp.end()){
            ans += mp[prefixSum - targetSum];
        }

        mp[prefixSum]++;

        solveDFS(root->left, targetSum, mp, ans, prefixSum);
        solveDFS(root->right, targetSum, mp, ans, prefixSum);

        mp[prefixSum]--;

        return ans;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;

        unordered_map<long long, long long> mp;
        mp[0] = 1;
        solveDFS(root, targetSum, mp, ans, 0);
        return ans;
    }
};