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
    ListNode* swapNodes(ListNode* head, int k) {
        // APPROACH 1 (2 passes)
        // TC -> O(n)
        // SC -> O(1)

        // int count = 0;
        // ListNode* curr = head;

        // while(curr != NULL){

        //     count++;
        //     curr = curr->next;
        // }

        // ListNode* Node1 = head;
        // for(int i = 1; i < k; i++){
        //     Node1 = Node1->next;
        // }

        // ListNode* Node2 = head;
        // int kFromEnd = count - k + 1;
        // for(int i = 1; i < kFromEnd; i++){
        //     Node2 = Node2->next;
        // }

        // swap(Node1->val, Node2->val);
        // return head;


        // APPROACH 2 (1 pass)
        // TC -> O(n)
        // SC -> O(1)

        ListNode* temp = head;
        ListNode* p1 = NULL;
        ListNode* p2 = NULL;

        for(int i = 1; i < k; i++){
            temp = temp->next;
        }

        p1 = temp;
        p2 = head;

        temp = temp->next;
        while(temp != NULL){
            temp = temp->next;
            p2 = p2->next;
        }

        swap(p1->val, p2->val);
        return head;
    }
};