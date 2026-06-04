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
    ListNode* middleNode(ListNode* head) {
        // APPROACH 1 (Traversal) 2-Passes
        // TC -> O(2n) -> O(n)
        // SC -> O(1)
        // int count = 0;
        // ListNode* curr = head;

        // while(curr != NULL){
        //     count++;
        //     curr = curr->next;
        // }

        // int mid = count / 2;
        // curr = head;

        // for(int i = 0; i < mid; i++){
        //     curr = curr->next;
        // }

        // return curr;


        // APPROACH 2 (Fast and Slow) 1-Pass
        // TC -> O(n)
        // SC -> O(1)


        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};