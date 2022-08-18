class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        priority_queue<int>pq; 
        for(auto c : mp){
            pq.push(c.second);
        }
        int cnt=0;
        int n = arr.size();
            while(n >arr.size()/2){
                int x = pq.top(); 
                pq.pop();
                cnt++;
                n-=x; 
            }
        return cnt;
    }
};