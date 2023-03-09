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
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *fastptr = head;
        ListNode *slowptr = head;
        
        while(fastptr != NULL && fastptr->next != NULL)
        {
            fastptr = fastptr->next->next;
            slowptr = slowptr->next;
            
            if(fastptr == slowptr)
                break;
        }
        
        if(fastptr == NULL || fastptr->next == NULL)
            return NULL;
        
        fastptr = head;
        
        while(fastptr != slowptr)
        {
            fastptr = fastptr->next;
            slowptr = slowptr->next;
        }
        
        return fastptr;
    }
};