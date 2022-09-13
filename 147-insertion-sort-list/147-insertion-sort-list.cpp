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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* dummy = new ListNode(-1);
        while(head){
            ListNode* temp = dummy;
            while(temp->next && temp->next->val < head->val){
                temp = temp->next;
            }
            ListNode* next = head->next;
            head->next = temp->next;
            temp->next = head;
            head = next;
        }
        return dummy->next;
    }
};