/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void solveDFS(Node* root){
        if(root == NULL || root->left == NULL){
            return;
        }

        root->left->next = root->right;

        if(root->next != NULL){
            root->right->next = root->next->left;
        }

        solveDFS(root->left);
        solveDFS(root->right);
    }

    Node* connect(Node* root) {
        // APPROACH 1 (BFS)
        // TC -> O(n)
        // SC -> O(n)

        // if(root == NULL){
        //     return root;
        // }

        // queue<Node*> q;
        // q.push(root);

        // while(!q.empty()){
        //     int size = q.size();

        //     while(size--){

        //         Node* temp = q.front();
        //         q.pop();

        //         if(size){
        //             temp->next = q.front();
        //         }

        //         if(temp->left){
        //             q.push(temp->left);
        //         }
        //         if(temp->right){
        //             q.push(temp->right);
        //         }
        //     }
        // }
        // return root;

        // APPROACH 2 (DFS)
        // TC -> O(n)
        // SC -> O(h)

        solveDFS(root);

        return root;
    }
};