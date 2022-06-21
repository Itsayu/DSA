class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int l=ladders;
        int b=bricks;
        priority_queue<int,vector<int>,greater<int>>q;
        int sum=0,n=heights.size();
        for(int i=1;i<n;i++){
            if(heights[i]>heights[i-1]){
                q.push(heights[i]-heights[i-1]);
                if(q.size()>l){
                    sum+=q.top();
                    q.pop();
                }
                if(sum>b){
                    return i-1;
                }
            }
        }
        return n-1;
    }
};