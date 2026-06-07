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
    ListNode* curr;
    
    bool rec(ListNode* head){
        if(head == NULL){
            return true;
        }

        bool ans = rec(head->next);

        if(head->val != curr->val){
            return false;
        }

        curr = curr->next;
        return ans;
    }

    // ListNode* reverseLL(ListNode* head){
    //     if(head == NULL || head->next == NULL){
    //         return head;
    //     }

    //     ListNode* curr = head;
    //     ListNode* nextNode = NULL;
    //     ListNode* prev = NULL;

    //     while(curr != NULL){

    //         nextNode = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = nextNode;
    //     }

    //     return prev;
    // }

    bool isPalindrome(ListNode* head) {
        // APPROACH 1
        // TC -> O(n)
        // SC -> O(n)

        // vector<int> temp;
        // ListNode* curr = head;

        // while(curr != NULL){

        //     temp.push_back(curr->val);
        //     curr = curr->next;
        // }

        // int i = 0, j = temp.size() - 1;

        // while(i < j){
        //     if(temp[i] != temp[j]){
        //         return false;
        //     }
        //     i++;
        //     j--;
        // }
        // return true;

        // APPROACH 2
        // TC -> O(n)
        // SC -> O(1)

        // if(head == NULL || head->next == NULL) return true;

        // ListNode* slow = head;
        // ListNode* fast = head;
        // ListNode* prev = NULL;

        // while(fast != NULL && fast->next != NULL){
        //     fast = fast->next->next;

        //     prev = slow;
        //     slow = slow->next;
        // }

        // ListNode* rightHalf = reverseLL(slow);

        // ListNode* left = head;
        // ListNode* right = rightHalf;

        // while(left != NULL && right != NULL){
            
        //     if(left->val != right->val){
        //         return false;
        //     }

        //     left  = left->next;
        //     right = right->next;
        // }
        // return true;

        // APPROACH 3
        // TC -> O(n)
        // SC -> O(1)

        // if(head == NULL || head->next == NULL) return true;

        // ListNode* slow = head;
        // ListNode* fast = head;
        // ListNode* prev = NULL;

        // while(fast != NULL && fast->next != NULL){

        //     fast = fast->next->next;

        //     ListNode* temp = slow->next;
        //     slow->next = prev;
        //     prev = slow;
        //     slow = temp;
        // }

        // // When fast is NULL, it means the list is even.
        // if(fast != NULL){
        //     slow = slow->next;
        // }

        // while(prev != NULL && slow != NULL){
        //     if(prev->val != slow->val){
        //         return false;
        //     }
        //     prev = prev->next;
        //     slow = slow->next;
        // }
        // return true;

        // APPROACH 4
        // TC -> O(n)
        // SC -> O(n)

        curr = head;

        return rec(head);
    }
};