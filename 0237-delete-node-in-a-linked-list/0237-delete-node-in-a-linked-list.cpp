/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *n = node;
        
        while(n->next->next!= NULL){
            n->val = n->next->val;
            n = n->next;
        }
        n->val = n->next->val;
        n->next = NULL;   
    }
};