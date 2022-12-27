class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& roc, int addrocks) {
        int n=cap.size();
        map<int,int> m;
        for(int i=0;i<n;i++)
            m[cap[i]-roc[i]]++;
        int ans=0;
        for(auto it:m){
            if(it.first*it.second<=addrocks){
                ans+=it.second;
                addrocks-=it.first*it.second;
            }else{
                ans+=addrocks/it.first;
                return ans;
            }
        }
        return ans;   
    }
};