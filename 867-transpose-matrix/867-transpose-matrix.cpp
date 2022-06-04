class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int a=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> ayu(n, vector<int>(a,0));  //copied
        for(int i=0; i<a; i++){
            for(int j=0; j<n; j++){
                ayu[j][i]= matrix[i][j];
            }
        }
        return ayu;
    }
};