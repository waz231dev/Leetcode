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
    int length(ListNode* head){
        if(!head)
            return 0;
        int len = 0;
        while(head != NULL){
            len++;
            head = head->next;
        }
        return len;
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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = length(head);
        
        if(k == 0 || k == len || len == 0 || k%len == 0)
            return head;
        head = reverse(head);
        ListNode* temp = head;
        k = k%len;
        
        for(int i = 1 ; i < k ; i++){
            temp = temp->next;
        }
        
        ListNode* head2 = reverse(temp->next);
        temp->next = NULL;
        ListNode* head1 = reverse(head);
        head->next = head2;
        
        return head1;
    }
};