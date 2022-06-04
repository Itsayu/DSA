class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& akt) {
        int a=akt.size();
        int n=akt[0].size();
        vector<vector<int>> ayu(n, vector<int>(a,0));  //copied
        for(int i=0; i<a; i++){
            for(int j=0; j<n; j++){
                ayu[j][i]= akt[i][j];
            }
        }
        return ayu;
    }
};