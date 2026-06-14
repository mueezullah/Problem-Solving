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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // TC -> O(n + k)
        // SC -> O(k)
        ListNode* curr = head;
        int len = 0;
        while(curr != NULL){
            len++;
            curr = curr->next;
        }

        int eachBucketNodes = len / k;
        int remainingNodes = len % k;

        vector<ListNode*> result(k, NULL);

        curr = head;
        ListNode* prev = NULL;

        for(int i = 0; i < k; i++){

            result[i] = curr;

            for(int count = 1; count <= eachBucketNodes + (remainingNodes > 0 ? 1 : 0); count++){

                prev = curr;
                curr = curr->next;
            }
            if(prev != NULL){
                prev->next = NULL;
            }
            remainingNodes--;
        }

        return result;
    }
};