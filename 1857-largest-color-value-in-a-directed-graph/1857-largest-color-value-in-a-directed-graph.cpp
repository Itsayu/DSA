class Solution {
public:
     vector<int>graph[100002];
    int largestPathValue(string s, vector<vector<int>>& edges) 
    {
    
        int n=s.size();
        vector<int>in(n,0);
        for(auto it:edges)
        {
            graph[it[0]].push_back(it[1]);
            in[it[1]]++;
        }
        queue<int>q;
        vector<vector<int>>dp(n,vector<int>(26,0));
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
            {
                q.push(i);
            }
        }
        int ans=0;
        vector<int>vis(n,0);
        while(q.size())
        {
            auto temp=q.front();
            q.pop();
            dp[temp][s[temp]-97]++;
            vis[temp]=1;
            for(int i=0;i<26;i++)
            {
                ans=max(ans,dp[temp][i]);
            }
            for(auto it:graph[temp])
            {
                in[it]--;
                if(in[it]==0)
                {
                    q.push(it);
                }
                for(int i=0;i<26;i++)
                {
                    dp[it][i]=max(dp[it][i],dp[temp][i]);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                return -1;
            }
        }
        return ans;
    }
};