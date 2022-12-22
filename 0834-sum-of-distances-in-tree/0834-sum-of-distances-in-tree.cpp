class Solution {
public:
    int n;
    vector<vector<int>> v;
    vector<int> val;
    vector<int> vall;
    vector<int> f;
    
    int dfs(int x,int p){
        for(int xx:v[x]){
            if(xx!=p){
                f[x]+=dfs(xx,x);
            }
        }
        f[x]++;
        return f[x];
    }
    
    int dfss(int x,int p){
        for(int xx:v[x]){
            if(xx!=p){
                val[x]+=dfss(xx,x)+f[xx];
            }
        }
        return val[x];
    }
    
    vector<int> solve(vector<vector<int>> edges){
        n=edges.size()+1;
        v.resize(n,vector<int> ());
        val.resize(n);
        vall.resize(n);
        f.resize(n);
        for(int i=0;i<n;i++){
            val[i]=vall[i]=0;
            f[i]=0;
        }
        for(auto it:edges){
            v[it[0]].push_back(it[1]);
            v[it[1]].push_back(it[0]);
        }
        dfs(0,-1);
        dfss(0,-1);
        
        queue<int> q;
        q.push(0);
        vector<int> vis(n,0);
        vall[0]=0;
        while(!q.empty()){
            int ff=q.size();
            while(ff--){
                int x=q.front();q.pop();
                for(int xx:v[x]){
                    if(!vis[xx]){
                        vall[xx]=vall[x]+val[x]-val[xx]-f[xx] + (n-f[xx]);
                        q.push(xx);
                    }
                }
                vis[x]=1;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(vall[i]+val[i]);
        }
        return ans;
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        return solve(edges);   
    }
};