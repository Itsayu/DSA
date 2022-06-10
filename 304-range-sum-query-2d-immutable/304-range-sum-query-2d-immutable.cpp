class NumMatrix {
private:
    vector<vector<int>>ayu;    
public:
    NumMatrix(vector<vector<int>>& matrix){
        ayu=vector(matrix.size()+1,vector(matrix[0].size()+1,0));
        
        for(int i=1;i<=matrix.size();i++){
            for(int j=1;j<=matrix[0].size();j++){
                ayu[i][j]=matrix[i-1][j-1]+ayu[i-1][j]+ayu[i][j-1]-ayu[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return ayu[row2+1][col2+1]-ayu[row2+1][col1]-ayu[row1][col2+1]+ayu[row1][col1];;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */