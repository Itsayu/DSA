class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        pq.push({nums[0],0});
        int ayu=nums[0];
        for(int i=1;i<n;i++){
            while(i-pq.top().second>k){
                pq.pop();
            }
            ayu=nums[i]+pq.top().first;
        pq.push({ayu,i});
        }
        return ayu;
    }
};