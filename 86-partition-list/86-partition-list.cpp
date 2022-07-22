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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(-201);
        ListNode* dummyTail = dummy;
        
        ListNode* temp = head;
        while(temp){
            if(temp->val<x){
                ListNode* newNode = new ListNode(temp->val);
                dummyTail->next = newNode;
                dummyTail = newNode;
            }
            temp = temp->next;
        }
        // ListNode* newNode = new ListNode(x);
        // dummyTail->next = newNode;
        // dummyTail = newNode;
        temp = head;
        // int flag = 0;
        
        while(temp){
           if(temp->val>=x){
                ListNode* newNode = new ListNode(temp->val);
                dummyTail->next = newNode;
                dummyTail = newNode;
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};