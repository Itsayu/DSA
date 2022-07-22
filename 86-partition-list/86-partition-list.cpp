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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL)
            return head;
        ListNode* temp=head;
        ListNode* list1=NULL;
        ListNode* list2=NULL;
        ListNode* head1=NULL;
        ListNode* head2=NULL;
        while(temp!=NULL){
            if(temp->val<x){
                if(head1==NULL){
                    head1=temp;
                    list1=temp;
                }
                else{
                    list1->next=temp;
                    list1=list1->next;
                }
            }
            else{
                if(head2==NULL){
                    head2=temp;
                    list2=temp;
                }
                else{
                    list2->next=temp;
                    list2=list2->next;
                }
            }
            temp=temp->next;
        }
        if(head1==NULL)
            return head2;
        list1->next=NULL;
        if(list2!=NULL)
            list2->next=NULL;
            list1->next=head2;
        return head1;
    }
};