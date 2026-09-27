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
    void inorder(TreeNode* root, vector<TreeNode*>& nodes){
        if(root == NULL){
            return;
        }

        inorder(root->left, nodes);
        nodes.push_back(root);
        inorder(root->right, nodes);
    }

    void recoverTree(TreeNode* root) {

        vector<TreeNode*> nodes;
        inorder(root, nodes);

        vector<int> treeVals;
        for(TreeNode* i : nodes){
            treeVals.push_back(i->val);
        }

        sort(treeVals.begin(), treeVals.end());

        for(int i = 0; i < nodes.size(); i++){
            if(nodes[i]->val != treeVals[i]){
                nodes[i]->val = treeVals[i];
            }
        }
    }
};