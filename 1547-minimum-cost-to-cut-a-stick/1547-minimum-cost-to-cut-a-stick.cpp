class Solution {
public:
    int minCost(int l, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(l);int n=cuts.size();
        vector<vector<int>> nr(n+1,vector<int>(n+1,9999999));
        for(int i=0;i<n-1;i++)
        {
            nr[i][i]=0;
        }
        for(int k=2;k<=n;k++)
        {
            for(int i=0;i<n-k;i++)
            {
                int j=i+k-1;
                for(int d=i;d<j;d++)
                {   
                    
                    nr[i][j]=min(nr[i][j],nr[i][d]+nr[d+1][j]+cuts[j+1]-cuts[i]);
                }
            }
        }
        return nr[0][n-2];
    }
};