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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // APPROACH 1 (HashSet)
        // TC -> O(n + m)
        // SC -> O(n)
        // ListNode* curr = headA;
        // unordered_set<ListNode*> vis;

        // while(curr != NULL){
        //     vis.insert(curr);
        //     curr = curr->next;
        // }

        // curr = headB;
        // while(curr != NULL){
            
        //     if(vis.find(curr) != vis.end()){
        //         return curr;
        //     }
        //     curr = curr->next;
        // }

        // return NULL;

        // APPROACH 2 (Two Pointers)
        // TC -> O(n + m)
        // SC -> O(1)

        ListNode* first = headA;
        ListNode* second = headB;

        while(first != second){
            first = first->next;
            second = second->next;

            if(first == second) return first;

            if(first == NULL){
                first = headB;
            }
            if(second == NULL){
                second = headA;
            }
        }

        return first;
    }
};