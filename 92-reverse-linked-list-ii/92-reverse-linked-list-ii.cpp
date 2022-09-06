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
    ListNode* reverse(ListNode* head,ListNode* end){
        ListNode* curr = head,*prev = NULL;
        while(curr != end){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        temp->next = head;
        ListNode* leftNode,*rightNode;
        int pos = 0;
        while(temp != NULL){
            if(pos == left-1){
                leftNode = temp;
            }
            if(pos == right){
                rightNode = temp->next;
            }
            temp = temp->next;
            ++pos;
        }
        // cout<<leftNode->val<<endl;
        ListNode* rev = reverse(leftNode->next,rightNode);
        leftNode->next->next = rightNode;
        leftNode->next = rev;
        return dummy->next;
    }
};