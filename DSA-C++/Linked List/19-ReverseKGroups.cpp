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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // TC -> O(n)
        // SC -> O(n/k) call stack depth

        // base case
        ListNode* check = head;
        for(int i = 0; i < k; i++){
            if(check == NULL){
                return head; // fewer than k, then return unchnaged
            }
            check = check->next;
        }

        // step 1: reverse k group
        ListNode* forward = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;

        int count = 0;

        while(curr != NULL && count < k){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;

            count++;
        }

        // step 2: recursion call
        if(forward != NULL){
            head->next = reverseKGroup(forward, k);
        }

        // step 3: return head of reversed list
        return prev;
    }
};