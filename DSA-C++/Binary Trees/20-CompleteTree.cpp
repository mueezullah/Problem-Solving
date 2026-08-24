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
    // int countNodes(TreeNode* root){
    //     if(root == NULL){
    //         return 0;
    //     }

    //     int left = countNodes(root -> left);
    //     int right = countNodes(root -> right);

    //     return 1 + (left + right);
    // }

    // bool solveDFS(TreeNode* root, int idx, int totalNodes){
    //     if(root == NULL){
    //         return true;
    //     }

    //     if(idx > totalNodes){
    //         return false;
    //     }

    //     if(idx == totalNodes){
    //         return true;
    //     }

    //     bool left = solveDFS(root->left, 2 * idx, totalNodes);
    //     bool right = solveDFS(root->right, 2 * idx + 1, totalNodes);

    //     return left && right;
    // }

    bool isCompleteTree(TreeNode* root) {
        // APPROACH 1 (DFS)
        // TC -> O(n)
        // SC -> O(h)
        // int totalNodes = countNodes(root);

        // int i = 1;
        // return solveDFS(root, i, totalNodes);

        // APPROACH 2 (BFS)
        // TC -> O(n)
        // SC -> O(n)

        queue<TreeNode*> q;
        q.push(root);
        bool isNULL = false;

        while(!q.empty()){

            int size = q.size();
            for(int i = 0; i < size; i++){

                TreeNode* temp = q.front();
                q.pop();

                if(temp == NULL){
                    isNULL = true;
                } else {
                    if(isNULL == true){
                        return false;
                    }

                    q.push(temp->left);
                    q.push(temp->right);
                }
            }

        }

        return true;
    }
};