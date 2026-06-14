/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // APPROACH 1
        // TC -> O(N)
        // SC -> O(N)

        // if(head == NULL){
        //     return NULL;
        // }
        
        // unordered_map<Node*, Node*> mp;

        // Node* curr = head;
        // Node* prev = NULL;
        // Node* newHead = NULL;

        // while(curr != NULL){

        //     Node* temp = new Node(curr->val);

        //     mp[curr] = temp;

        //     if(newHead == NULL){
        //         newHead = temp;
        //         prev = newHead;
        //     } else {
        //         prev->next = temp;
        //         prev = temp;
        //     }
        //     curr = curr->next;
        // }

        // // fill random pointers
        // curr = head;
        // Node* newCurr = newHead;

        // while(curr != NULL){
        //     if(curr->random == NULL){
        //         newCurr->random = NULL;
        //     }
        //     else {
        //         newCurr->random = mp[curr->random];
        //     }

        //     curr = curr->next;
        //     newCurr = newCurr->next;
        // }

        // return newHead;

        // APPROACH 2
        // TC -> O(N)
        // SC -> O(N)/O(1) (Debatable)

        if(head == NULL) {
            return NULL;
        }

        Node* curr = head;

        while(curr != NULL){
            Node* currNext = curr->next; // B, curr = A
            curr->next = new Node(curr->val); // A -> B
            curr->next->next = currNext; // A-> X -> B

            curr = currNext; // curr = B
        }

        // deep copy of pointers
        curr = head;
        while(curr != NULL && curr->next != NULL){

            if(curr->random == NULL){
                curr->next->random = NULL;
            } else {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // separate the linked lists
        Node* newHead = head->next;
        Node* newCurr = newHead;
        curr = head;

        while(curr != NULL && newCurr != NULL){

            curr->next = curr->next == NULL ? NULL : curr->next->next;

            newCurr->next = newCurr->next == NULL ? NULL : newCurr->next->next;

            curr = curr->next;
            newCurr = newCurr->next;
        }

        return newHead;
    }
};