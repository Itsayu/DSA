class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
        for(auto i:arr){
            p.push(make_pair(abs(i-x),i));
        }
        vector<int> ans;
        while(k--){
            ans.push_back(p.top().second);
            p.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};