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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // APPROACH 1 (Recursion)
        // TC -> O(n + m)
        // SC -> O(n + m)

        // if(list1 == NULL){
        //     return list2;
        // }
        // if(list2 == NULL){
        //     return list1;
        // }

        // ListNode* result;
        // if(list1->val < list2->val){
        //     result = list1;
        //     result->next = mergeTwoLists(list1->next, list2);
        // } else{
        //     result = list2;
        //     result->next = mergeTwoLists(list1, list2->next);
        // }

        // return result;


        // APPROACH 2 (Iterative)
        // TC -> O(n + m)
        // SC -> O(1)

        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode dummyNode(-1);
        ListNode* temp = &dummyNode;
        
        while(list1 != NULL && list2 != NULL){
            
            if(list1->val < list2->val){
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
        }

        if(list1 != NULL){
            temp->next = list1;
        }
        if(list2 != NULL){
            temp->next = list2;
        }

        return dummyNode.next;
    }
};