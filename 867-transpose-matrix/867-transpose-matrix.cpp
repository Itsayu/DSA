class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int r=matrix[0].size();
        vector<vector<int>> ayu(r, vector<int>(n,0));  //copied
        for(int i=0; i<n; i++){
            for(int j=0; j<r; j++){
                ayu[j][i]= matrix[i][j];
            }
        }
        return ayu;
    }
};