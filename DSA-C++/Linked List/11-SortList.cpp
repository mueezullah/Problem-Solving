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
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* l1, ListNode* l2){
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        ListNode dummyNode(-1);
        ListNode* temp = &dummyNode;

        while(l1 != NULL && l2 != NULL){

            if(l1->val < l2->val){
                temp->next = l1;
                l1 = l1->next;
            }
            else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }

        if(l1 != NULL){
            temp->next = l1;
        }
        if(l2 != NULL){
            temp->next = l2;
        }
        
        return dummyNode.next;
    }

    ListNode* sortList(ListNode* head) {
        // APPROACH 1
        // TC -> O(N log N)
        // SC -> O(N)

        // ListNode* curr = head;
        // vector<int> list;

        // while(curr != NULL){
        //     list.push_back(curr->val);
        //     curr = curr->next;
        // }

        // sort(list.begin(), list.end());

        // curr = head;
        // int i = 0;
        // while(curr != NULL){
        //     curr->val = list[i];
        //     i++;
            
        //     curr = curr->next;
        // }

        // return head;


        // APPROACH 2
        // TC -> O(n log n)
        // SC -> O(log n)

        if(head == NULL || head->next == NULL) return head;

        ListNode* mid = findMid(head);
        ListNode* rightHalf = mid->next;
        mid->next = NULL;

        ListNode* left  = sortList(head);
        ListNode* right = sortList(rightHalf);

        return merge(left, right);
    }
};