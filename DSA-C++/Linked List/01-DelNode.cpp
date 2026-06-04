/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // APPROACH 1
        // TC -> O(n)
        // SC -> O(1)
        // ListNode* prev = NULL;

        // while(node != NULL && node->next != NULL){
        //     node->val = node->next->val;

        //     prev = node;

        //     node = node->next;
        // }
        // prev->next = NULL;
        // delete(node);

        // APPROACH 2
        // TC -> O(1)
        // SC -> O(1)

        ListNode* temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete temp;
    }
};