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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* dummy = head;
        ListNode* curr = head->next;
        
        while(curr){
            ListNode* temp = curr->next;
            while(temp->val != 0){
                curr->val += temp->val;
                temp = temp->next;
            }
            curr->next = temp->next;
            curr = temp->next;
        }
        return dummy->next;
    }
};