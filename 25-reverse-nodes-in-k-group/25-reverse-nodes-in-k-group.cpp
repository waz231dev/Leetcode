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
    ListNode* reverse(ListNode* first,ListNode* last){
        ListNode* prev =  NULL;
        ListNode* curr = first;
        
        while(curr != last){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        
        ListNode* rh = NULL;
        ListNode* rt = head;
        
        ListNode* temp = head;
        
        while(head){
            ListNode* temp = head;
            int i;
            for(i = 0 ; i < k && head; i++){
                head = head->next;
            }
            if(i != k){
                rt->next = temp;
                break;
            }
            if(rh == NULL){
                rh = reverse(temp,head);
            }else{
                rt->next = reverse(temp,head);
            }
            rt = temp;
        }
        return rh;
    }
};