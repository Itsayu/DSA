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
    bool check(ListNode*&p1, ListNode* p2){
        if(p2==nullptr || p1 == nullptr)
            return true;
        
        bool ans = check(p1,p2->next);
        
        if(!ans)
            return false;
        
        ans = (p1->val == p2->val);
        p1=p1->next;
        return ans;
    }
    
    bool isPalindrome(ListNode* head) {
        return check(head,head);
        
    }
};