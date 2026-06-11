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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }
        int len = 0;
        ListNode* curr = head;

        while(curr != NULL){
            len++;
            curr = curr->next;
        }

        curr = head;

        k = k % len;
        if(k == 0){
            return head;
        }

        int remain = len - k;

        for(int i = 1; i < remain; i++){
            curr = curr->next;
        }

        ListNode* newHead = curr->next;
        curr->next = NULL;

        curr = newHead;
        while(curr->next != NULL){
            curr = curr->next;
        }
        
        curr->next = head;
        return newHead;
    }
};