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
    int pairSum(ListNode* head) {
        int res=0;
        vector<int> arr;
        while(head->next!=NULL){
            arr.push_back(head->val);
            head=head->next;
        }
        arr.push_back(head->val);
        for(auto x:arr){
            cout<<x<<" ";
        }
        cout<<'\n';
        for(int i=0;i<(int)arr.size()/2;i++){
            res=max(res,arr[i]+arr[(int)arr.size()-i-1]);
        }
        return res;
    }
};