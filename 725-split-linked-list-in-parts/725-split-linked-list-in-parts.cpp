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
    int length(ListNode* head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = length(head);
        int n = len/k;
        int extra = len%k;
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        // cout<<extra;
        vector<ListNode*> ans(k,NULL);
        for(int i = 0 ; i < k ; i++){
            ans[i] = curr;
            
            for(int i = 0; i < n && curr; i++){
                prev = curr;
                // cout<<prev->val;
                curr = curr->next;
            }
            // cout<<prev->val;
            if(extra && curr){
                prev = curr;
                // cout<<prev->val;
                curr = curr->next;
                extra--;
            }
            
            if(prev)
                prev->next = NULL;
            
        }
        return ans;
    }
};