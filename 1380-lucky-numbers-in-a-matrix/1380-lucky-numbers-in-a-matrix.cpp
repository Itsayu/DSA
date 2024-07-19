class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) 
			{
				vector<int> ans;
				int n=matrix.size();
				int m=matrix[0].size();

				for(int i=0;i<n;i++)
				{
					int min=0;
					for(int j=0;j<m;j++)
					{
						if(matrix[i][min]>matrix[i][j])
							min=j;
					}
					int lucky=matrix[i][min];
					bool flag=1;
					for(int k=0;k<n;k++)
					{
						if(matrix[k][min]>lucky)
						{
							flag=0;
							break; 
						}
					}
					if(flag==1)
						ans.push_back(lucky);
				}
				return ans;
    }
};