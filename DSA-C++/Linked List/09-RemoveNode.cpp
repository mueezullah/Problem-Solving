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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // APPROACH 1 (2 Pass)
        // TC -> O(n)
        // SC -> O(1)
        // ListNode* curr = head;
        // int len = 0;

        // while(curr != NULL){
        //     len++;
        //     curr = curr->next;
        // }

        // if(n == len){
        //     ListNode* newHead = head->next;
        //     delete head;
        //     return newHead;
        // }

        // int nodeToRemove = len - n - 1;
        // ListNode* prev = head;

        // while(nodeToRemove--){
        //     prev = prev->next;
        // }

        // ListNode* delNode = prev->next;
        // prev->next = delNode->next;

        // delete delNode;
        // return head;


        // APPROACH 2 (1 Pass)
        // TC -> O(n)
        // SC -> O(1)

        ListNode* temp = head;

        for(int i = 1; i <= n; i++){
            temp = temp->next;
        }

        if(temp == NULL){
            ListNode* res = head->next;
            delete head;
            return res;
        }
        
        ListNode* prev = head;
        while(temp != NULL && temp->next != NULL){
            prev = prev->next;
            temp = temp->next;
        }

        ListNode* delNode = prev->next;
        prev->next = prev->next->next;

        delete delNode;
        return head;

    }
};
