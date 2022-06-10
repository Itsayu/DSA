class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>nr;
        for(int i=0;i<numRows;i++)
        {
            vector<int> row(i+1,1);
            for(int j=1;j<i;j++)
            {
                row[j]=nr[i-1][j-1]+nr[i-1][j];
            }
            nr.push_back(row);
        }
        return nr;
    }
};