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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* KthFirst = NULL;
        ListNode* KthLast = NULL;
        
        for(ListNode* ptr = head ; ptr != NULL ; ptr = ptr->next){
            if(KthLast)
                KthLast = KthLast->next;
            if(--k == 0){
                KthFirst = ptr;
                KthLast = head;
            }
        }
        
        int temp = KthFirst->val;
        KthFirst->val = KthLast->val;
        KthLast->val = temp;
        return head;
    }
};