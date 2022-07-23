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
class Compare {
    public:
        bool operator()(ListNode* l1,ListNode* l2){
            return l1->val > l2->val;
        }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        priority_queue<ListNode*,vector<ListNode*>,Compare> pq;
        
        for(auto list : lists){
            if(list)
            pq.push(list);
        }
        
        ListNode dummy(-1);
        ListNode* temp = &dummy;
        
        
        while(!pq.empty()){
            ListNode* top = pq.top();
            pq.pop();
            
            temp->next = top;
            temp = temp->next;
            if(top->next)
                pq.push(top->next);
        }
        return dummy.next;
    }
};