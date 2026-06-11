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
    // TC -> O(n)
    // SC -> O(1)
    ListNode* reverseLL(ListNode* head){
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

    void reorderList(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* revHead = reverseLL(slow->next);
        slow->next = NULL;

        ListNode* left = head;
        ListNode* right = revHead;

        ListNode* leftNext = NULL;
        ListNode* rightNext = NULL;

        while(right != NULL){
            leftNext = left->next;
            rightNext = right->next;

            left->next = right;
            right->next = leftNext;
            
            left = leftNext;
            right = rightNext;
        }


    }
};