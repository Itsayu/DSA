class Solution {
public:
    int uniquePaths(int m, int n) {
        double num=1;
        for(int i=1; i<n; i++)
        {
            num *=m-1+i;
            num /=i;
        }
        return (int)num;
    }
};