class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> outdegree(n+1),indegree(n+1);
        for(int i=0;i<trust.size();i++){
            outdegree[trust[i][0]]++;
            indegree[trust[i][1]]++;
        }

        for(int i=1;i<n+1;i++){
            if(indegree[i]==(n-1) && outdegree[i]==0) return i;
        }
        return -1; 
    }
};