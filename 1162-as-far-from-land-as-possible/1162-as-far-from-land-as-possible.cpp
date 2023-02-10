class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
		vector<vector<int>>v(grid.size(), vector<int>(grid[0].size(), 0));
		queue<pair<pair<int, int>, int>>q;
		int ans=0, c0=0;
		for(int i=0; i<grid.size(); i++){
			for(int j=0; j<grid[0].size(); j++){
				if(grid[i][j]==0){c0++;}
				if(!v[i][j] && grid[i][j]==1){
					v[i][j]=1;
					q.push({{i, j}, 0});
				}
			}
		}
		if(c0==0 || c0==grid.size()*grid[0].size()){return -1;}
		while(!q.empty()){
			int x=q.front().first.first, y=q.front().first.second, cnt=q.front().second;
			q.pop();
			ans=max(ans, cnt);
			//cout<<cnt<<endl;
			if(x>0 && !v[x-1][y]){
				v[x-1][y]=1;
				q.push({{x-1, y}, cnt+1});
			}
			if(y>0 && !v[x][y-1]){
				v[x][y-1]=1;
				q.push({{x, y-1}, cnt+1});
			}
			if(x<grid.size()-1 && !v[x+1][y]){
				v[x+1][y]=1;
				q.push({{x+1, y}, cnt+1});
			}
			if(y<grid[0].size()-1 && !v[x][y+1]){
				v[x][y+1]=1;
				q.push({{x, y+1}, cnt+1});
			}
		}
		return ans;

    }
};