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
    ListNode* reverseList(ListNode* head) {
        // APPROACH 1 (Recursion)
        // TC -> O(n)
        // SC -> O(n)
        
        // if(head == NULL || head->next == NULL){
        //     return head;
        // }

        // ListNode* lastHead = reverseList(head->next);

        // head->next->next = head;
        // head->next = NULL;

        // return lastHead;

        // APPROACH 2 (Iterative)
        // TC -> O(n)
        // SC -> O(1)

        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* curr = head;
        ListNode* nextNode = NULL;
        ListNode* prev = NULL;

        while(curr != NULL){

            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
};