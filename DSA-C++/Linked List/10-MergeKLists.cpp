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
    // TC -> O(N log K)
    // SC -> O(log K)
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){

        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        ListNode dummyNode(-1);
        ListNode* temp = &dummyNode;

        while(l1 != NULL && l2 != NULL){
            
            if(l1->val < l2->val){
                temp->next = l1;
                temp = temp->next;
                l1 = l1->next;
            } else {
                temp->next = l2;
                temp = temp->next;
                l2 = l2->next;
            }
        }

        if(l1 != NULL){
            temp->next = l1;
        }
        if(l2 != NULL){
            temp->next = l2;
        }

        return dummyNode.next;
    }

    ListNode* partitionAndMerge(int start, int end, vector<ListNode*>& lists){
        if(start > end){
            return NULL;
        }

        if(start == end){
            return lists[start];
        }

        int mid = start + (end - start) / 2;

        ListNode* L1 = partitionAndMerge(start, mid, lists);
        ListNode* L2 = partitionAndMerge(mid+1, end, lists);

        return mergeTwoLists(L1, L2);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int k = lists.size();
        if(k == 0){
            return NULL;
        }
        return partitionAndMerge(0, k-1, lists);
    }
};