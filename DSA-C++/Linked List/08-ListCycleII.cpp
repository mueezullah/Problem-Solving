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
    ListNode *detectCycle(ListNode *head) {
        // APPROACH 1 (Set)
        // TC -> O(n)
        // SC -> O(n)

        // if(head == NULL || head->next == NULL) return NULL;

        // ListNode* curr = head;
        // unordered_set<ListNode*> visited;

        // while(curr != NULL){

        //     if(visited.find(curr) != visited.end()){
        //         return curr;
        //     }

        //     visited.insert(curr);
        //     curr = curr->next;
        // }

        // return NULL;

        // APPROACH 2 (Slow and Fast)
        // TC -> O(n)
        // SC -> O(1)

        if(head == NULL || head->next == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                break;
            }
        }

        if(slow == fast){
            ListNode* verify = head;

            while(verify != slow){
                verify = verify->next;
                slow = slow->next;
            }
            return slow;
        }
        return NULL;
    }
};