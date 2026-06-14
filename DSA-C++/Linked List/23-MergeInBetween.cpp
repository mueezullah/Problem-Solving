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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* forward = list1;
        ListNode* curr = list1;

        for(int i = 1; i <= b; i++){
            forward = forward->next;
        }
        forward = forward->next;

        for(int i = 1; i < a; i++){
            curr = curr->next;
        }

        curr->next = list2;
        curr = list2;
        ListNode* second = list2;

        while(second != NULL){
            second = second->next;
            if(second == NULL){
                continue;
            }else{
                curr = curr->next;
            }
        }
        curr->next = forward;
        return list1;
    }
};