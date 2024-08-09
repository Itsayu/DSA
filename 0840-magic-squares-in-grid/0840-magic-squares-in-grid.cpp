class Solution {
public:
    bool isValid(int row, int col, vector<vector<int>> &grid){
        map<int, int> mp;
        vector<int> helper;
        for(int i=row; i<(row+3); i++){
            int sum=0;
            for(int j=col; j<(col+3); j++){
                if(mp.find(grid[i][j])!=mp.end() || grid[i][j]<1 || grid[i][j]>9) return false;
                mp[grid[i][j]]=i;
                sum+=grid[i][j];
            }
            helper.push_back(sum);
        }

        for(int j=col; j<(col+3); j++){
            int sum=0;
            for(int i=row; i<(row+3); i++){
                sum+=grid[i][j];
            }
            helper.push_back(sum);
        }

        int sum=grid[row][col]+grid[row+1][col+1]+grid[row+2][col+2];
        helper.push_back(sum);
        sum=grid[row][col+2]+grid[row+1][col+1]+grid[row+2][col];
        helper.push_back(sum);

        for(int i=1; i<helper.size(); i++){
            if(helper[i]!=helper[i-1]) return false;
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        // do bruteforce 
        int row=grid.size();
        int col=grid[0].size();
        int ans=0;
        for(int i=0; i<=(row-3); i++){
            for(int j=0; j<=(col-3); j++){
                if(isValid(i, j, grid)) ans++;
            }
        }
        return ans;
    }
};