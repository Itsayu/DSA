class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n==1)
            return triangle[0][0];
        else
        {
            for(int j=n-2;j>=0;j--)
            {
                for(int i=0;i<triangle[j].size();i++)
                {
                    triangle[j][i] += min(triangle[j+1][i],triangle[j+1][i+1]);    
                }
            }
        }
        
        return triangle[0][0];
    }
};