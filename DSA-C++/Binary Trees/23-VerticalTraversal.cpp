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
    // map<int, map<int, multiset<int>>> nodes;

    // void dfs(TreeNode* root, int x, int y){
    //     if(root == NULL){
    //         return;
    //     }

    //     nodes[x][y].insert(root->val);

    //     dfs(root->left, x - 1, y + 1);

    //     dfs(root->right, x + 1, y + 1);
    // }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // APPROACH 1 (BFS)
        // TC -> O(n log n) due to set and multiset insertions
        // SC -> O(n)
        map<int, map<int, multiset<int>>> nodes;
        queue< pair<TreeNode*, pair<int, int>>> q;
        vector<vector<int>> ans;

        if(root == NULL){
            return ans;
        }

        q.push(make_pair(root, make_pair(0, 0)));
        while(!q.empty()){
            pair<TreeNode*, pair<int, int> > temp = q.front();
            q.pop();

            TreeNode* frontNode = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;

            nodes[x][y].insert(frontNode->val);

            if(frontNode->left)
                q.push(make_pair(frontNode->left, make_pair(x-1, y+1)));
            if(frontNode->right)
                q.push(make_pair(frontNode->right, make_pair(x+1, y+1)));
        }

        for(auto i : nodes){
            vector<int> col;
            for(auto j : i.second){
                for(auto k : j.second){
                    col.push_back(k);
                }
            }
            ans.push_back(col);
        }

        return ans;


        // APPROACH 2 (DFS)
        // TC -> O(n log n)
        // SC -> O(h)

        // vector<vector<int>> ans;

        // dfs(root, 0, 0);

        // for(auto i : nodes){
        //     vector<int> col;
        //     for(auto j : i.second){
        //         for(auto k : j.second){
        //             col.push_back(k);
        //         }
        //     }
        //     ans.push_back(col);
        // }
        // return ans;
    }
};