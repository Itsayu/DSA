class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n=coordinates.size();
        if(n==1) return true;
        double x1=coordinates[0][0];
        double y1=coordinates[0][1];
        double x2=coordinates[1][0];
        double y2=coordinates[1][1];
        double m;
        if(x2-x1==0){
            double X=coordinates[0][0];
            for(int i=0;i<n;i++){
                if(coordinates[i][0]!=X) return false;
            }
            return true;
        }
        else if(y2-y1==0){
            double Y=coordinates[0][1];
            for(int i=0;i<n;i++){
                if(coordinates[i][1]!=Y) return false;
            }
            return true;
        }
        m=(y2-y1)/(x2-x1);
        for(int i=1;i<n;i++){
            double y=(m*(coordinates[i][0]-x1))+y1;
            if((double)coordinates[i][1]!=y) return false;
        }
        return true;
    }
};