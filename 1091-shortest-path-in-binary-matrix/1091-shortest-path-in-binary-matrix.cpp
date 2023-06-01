class Solution {
public:
    int dx[8] = {0,1,1,0,1,-1,-1,-1};
    int dy[8] = {1,0,1,-1,-1,0,-1,1};
    bool isValid(vector<vector<int>>& arr,int x,int y){
        if(x >= 0 && x < arr.size() && y >= 0 && y < arr.size() && arr[x][y] == 0)
            return true;
        return false;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& arr) {
        if(arr[0][0] != 0)  return -1;
        
        int n = arr.size();
        vector<vector<int> > vis(n,vector<int>(n,INT_MAX));
        queue<pair<int,int> > q;
        q.push({0,0});
        vis[0][0] = 0;
        while(!q.empty()){
            int size = q.size();
            while(size-- > 0){
                auto curr = q.front();  q.pop();
                int x = curr.first;
                int y = curr.second;
                for(int i=0;i<8;i++){
                    int a = x + dx[i];
                    int b = y + dy[i];
                    if(isValid(arr,a,b) && vis[a][b] > 1 + vis[x][y]){
                        vis[a][b] = 1 + vis[x][y];
                        q.push({a,b});
                    }
                }
                
            }
        }
        return vis[n-1][n-1] != INT_MAX ? vis[n-1][n-1] + 1 : -1;
    }
};