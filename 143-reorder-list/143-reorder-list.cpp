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
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;        
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head)
            return;
        
        ListNode* mid = getMid(head);
        ListNode* head2 = mid->next;
        mid->next = NULL;
        ListNode* head1 = head;
        head2 = reverse(head2);
        while(head2){
            ListNode* next1 = head1->next;
            ListNode* next2 = head2->next;
            
            head1->next = head2;
            head2->next = next1;
            
            head1 = next1;
            head2 = next2;
        }
        return;
    }
};