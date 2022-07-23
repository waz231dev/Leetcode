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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* mid = getMid(head);
        ListNode* head2 = mid->next;
        mid->next = NULL;
        head = sortList(head);
        head2 = sortList(head2);
        head = mergeLists(head,head2);
        return head;
    }
    
    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* mergeLists(ListNode* head1,ListNode* head2){
        if(head1 == NULL)
            return head2;
        if(head2 == NULL)
            return head1;
        
        ListNode* head;
        if(head1->val < head2->val){
            head1->next = mergeLists(head1->next,head2);
            return head1;
        }
            head2->next = mergeLists(head1,head2->next);
            return head2;        
    }
};