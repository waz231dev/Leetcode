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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head,*prev=NULL;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int length(ListNode* head){
        int len = 0;
        while(head!= NULL){
            head = head->next;
            len++;
        }
        return len;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(length(l2) > length(l1)){
            return addTwoNumbers(l2,l1);
        }
        l1 = reverse(l1);
        l2 = reverse(l2);
        int c = 0;
        ListNode* temp = l1;
        // cout<<l1->val<<endl;
        while(temp){
            temp->val += (l2 != NULL ? l2->val+c : c);
            c = temp->val/10;
            temp->val %= 10;
            
            temp = temp->next;
            if(l2)
            l2 = l2->next;
        }
        // cout<<l1->val<<endl;
        l1 = reverse(l1);
        // cout<<l1->val<<endl;
        if(c){
            ListNode* newNode = new ListNode(1);
            newNode->next = l1;
            l1 = newNode;
        }
        return l1;
    }
};