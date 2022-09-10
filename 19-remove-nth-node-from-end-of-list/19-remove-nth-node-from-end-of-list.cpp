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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp = NULL;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        for(auto ptr = head ; ptr != NULL ; ptr = ptr->next){
            if(temp){
                prev = temp;
                temp = temp->next;
            }
            if(--n == 0){
                temp = head;
            }
        }
        prev->next = prev->next->next;
        return dummy->next;
    }
};