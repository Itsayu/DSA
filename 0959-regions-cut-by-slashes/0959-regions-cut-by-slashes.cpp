class Solution {
public:
    int n,count;

    int getCell(int i,int j, int k){
        return (i*n*4+j*4+k);
    }

    int getAbsoluteParent(int x,vector<int>&ng){
        if(x==ng[x])
            return x;
        if(x!=ng[x]){
            ng[x] = getAbsoluteParent(ng[x],ng);
        }
        return ng[x];
    }

    void unify(int x, int y, vector<int>&ng){
        int p = getAbsoluteParent(x,ng);
        int q = getAbsoluteParent(y,ng);
        if(p!=q){
            ng[p] = q;
            count--;
        }       
    }

    int regionsBySlashes(vector<string>& grid) {
        n=grid.size();
        count = n*n*4;
        vector<int>ng(count);
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<4;k++)
                    ng[i*n*4+j*4+k] = i*n*4+j*4+k;

        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i>0)
                    unify(getCell(i-1,j,2),getCell(i,j,0),ng);

                if(j>0)
                    unify(getCell(i,j-1,1),getCell(i,j,3),ng);

                if(grid[i][j]=='/'){
                    unify(getCell(i,j,0),getCell(i,j,3),ng);
                    unify(getCell(i,j,1),getCell(i,j,2),ng);
                }else if(grid[i][j]=='\\'){
                    unify(getCell(i,j,0),getCell(i,j,1),ng);
                    unify(getCell(i,j,2),getCell(i,j,3),ng);
                }else {
                    unify(getCell(i,j,0),getCell(i,j,1),ng);
                    unify(getCell(i,j,2),getCell(i,j,3),ng);
                    unify(getCell(i,j,0),getCell(i,j,3),ng);
                    unify(getCell(i,j,1),getCell(i,j,2),ng);
                }
            }
        }

        return count;
    }
};