class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
	    int v = INT_MAX-10000;
	    vector<vector<int>> DP (n, vector<int> (target+1, v));
	    for(int i=0; i<n; i++){
		    DP[i][0] = 0;
	    }
        for(int i=0; i<m; i++){
		    for(int j=min(i+1,target);j>0;j--){
                for(int k=0; k<n; k++){
				    if(houses[i] != 0){
					    if(k != houses[i]-1){
						    DP[k][j] = v;
						    continue;
					    }
                        if(i==0 && j==1)
                            DP[k][j] = 0;
					    if(i!=0 && j==1)
                            continue;
                        for(int m=0;m<n;m++){
						    if(k==m)
                                continue;
						    DP[k][j]=min(DP[k][j],DP[m][j-1]);
					    }
					    continue;
				    }
				    DP[k][j]=DP[k][j]+cost[i][k];
				    if(DP[k][j] > v)
                        DP[k][j]=v;
                    if(i!=0 && j==1)
                        continue;
				for(int m=0; m<n; m++){
					if(k==m) continue;
					DP[k][j]=min(DP[k][j], DP[m][j-1]+cost[i][k]);
				}
			}
		}
	}
	int mn = v;
	for(int i=0; i<n; i++){
		if(mn>DP[i][target]){
			mn=DP[i][target];
		}
	}
    return (mn==v) ? -1:mn;
    }
};