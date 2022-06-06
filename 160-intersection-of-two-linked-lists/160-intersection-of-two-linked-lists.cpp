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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ayu=headA;
        
        while(ayu!=NULL)
        {
            ListNode *akt=headB;
            while(akt!=NULL)
            {
                if(ayu==akt)
                    return ayu;
                else
                    akt=akt->next;
            }
            ayu=ayu->next;
        }
        
        return NULL;
    }
};