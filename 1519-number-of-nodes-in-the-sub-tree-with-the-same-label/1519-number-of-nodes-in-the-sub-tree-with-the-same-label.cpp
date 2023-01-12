class Solution {
public:
    vector<int> dfs(vector<vector<int>> &x,vector<int> &ans,int i,string& labels){
        vector<int> a(26,0);
        if(ans[i]) return a;
        ans[i]=1;
        a[labels[i]-'a']++;
        for(int j=0;j<x[i].size();j++){
            vector<int> b = dfs(x,ans,x[i][j],labels);
            for(int k=0;k<26;k++){
                a[k]+=b[k];
            }
        }
        ans[i]=a[labels[i]-'a'];
        return a;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> x(n,vector<int>());
        for(int i=0;i<n-1;i++){
            x[edges[i][0]].push_back(edges[i][1]);
            x[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> ans(n,0);
        dfs(x,ans,0,labels);
        return ans;   
    }
};