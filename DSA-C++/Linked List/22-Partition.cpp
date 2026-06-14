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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* small = new ListNode(-1);
        ListNode* smallCurr = small;
        ListNode* large = new ListNode(-1);
        ListNode* largeCurr = large;
        ListNode* curr = head;

        while(curr != NULL){

            if(curr->val < x){
                smallCurr->next = curr;
                smallCurr = smallCurr->next;
            } else {
                largeCurr->next = curr;
                largeCurr = largeCurr->next;
            }
            curr = curr->next;
        }

        smallCurr->next = large->next;
        largeCurr->next = NULL;
        
        return small->next;
    }
};