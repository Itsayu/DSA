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
    ListNode* reverseBetween(ListNode* head, int m, int o) {
        if(!head) return head;
        ListNode *t1=nullptr,*t2=head;
        for(int i=0;i<m-1;i++){
            t1=t2;
            t2=t2->next;
        } 
        int cnt=0;
        ListNode *c=t2,*p=nullptr,*n;
        while(cnt<o-m+1){
            n=c->next;
            c->next=p;
            p=c;
            c=n;
            cnt++;
        }
        if(!t1) head=p;
        else t1->next=p;
        t2->next=c;
        return head;
    }
};