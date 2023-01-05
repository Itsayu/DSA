class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        
        int small = INT_MIN ;
        int count = 0 ;
        
        for(auto k:points)
        {
            if( small == INT_MIN )
            {
                small = k[1];
                continue ;
            }
            if( k[0] <= small && small > k[1] )
            {
                small = k[1];
                continue ;
            }
            if( k[0] <= small )
                continue;
            else
            {
                count++ ;
                small = k[1] ;
            }
        }
        
        return count+1 ;
    }
};