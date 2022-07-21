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
    void reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* prevLeft = left > 1? head : NULL;
        ListNode* leftNode;
        ListNode* rightNode = head;
        ListNode* nextRight;
        
        int i = 1;
        while(prevLeft && i < left-1){
            prevLeft = prevLeft->next;
            i++;
        }
        leftNode = prevLeft ? prevLeft->next : head;
        i = 1;
        while(rightNode && i < right){
            rightNode = rightNode->next;
            i++;
        }
        nextRight = rightNode->next;
        rightNode->next = NULL;
        reverse(leftNode);
        if(prevLeft)
            prevLeft->next = rightNode;
        else
            head = rightNode;
        
        leftNode->next = nextRight;
        
        return head;
    }
};