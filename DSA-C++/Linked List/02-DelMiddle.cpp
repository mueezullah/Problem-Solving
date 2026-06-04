/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        // APPROACH 1 (Count + Traversal) 2 passes
        // TC -> O(n)
        // SC -> O(1)

        // if(head == NULL || head->next == NULL){
        //     return NULL;
        // }

        // int count = 0;
        // ListNode* curr = head;
        // while(curr != NULL){
        //     count++;
        //     curr = curr->next;
        // }

        // int mid = count / 2;

        // curr = head;
        // for(int i = 0; i < mid-1; i++){

        //     curr = curr->next;
        // }

        
        // ListNode* toDelete = curr->next;
        // curr->next = curr->next->next;
        // delete toDelete;

        // return head;

        // APPROACH 2 (Slow and Fast Pointer) 1 pass
        // TC -> O(n)
        // SC -> O(1)

        if(head == NULL || head->next == NULL){
            return NULL;
        }

        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            prev = slow;

            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        delete slow;
        return head;
    }
};