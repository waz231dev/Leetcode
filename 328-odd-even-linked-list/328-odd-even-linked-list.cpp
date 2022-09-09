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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(-1);
        ListNode* even = new ListNode(-1);
        ListNode* po = odd;
        ListNode* pe = even;
        
        ListNode* curr = head;
        int i = 1;
        while(curr){
            if(i){
                po->next = curr;
                po = curr;
            }else{
                pe->next = curr;
                pe = curr;
            }
            curr = curr->next;
            i = i^1;
        }
        
        pe->next = NULL;
        po->next = even->next;
        return odd->next;
    }
};