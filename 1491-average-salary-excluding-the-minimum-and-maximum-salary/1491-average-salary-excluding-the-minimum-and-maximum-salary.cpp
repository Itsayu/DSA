class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        double nr = 0;
		
        sort(salary.begin(), salary.end());
		
        for(int i = 1; i < n-1; i++){
            nr += salary[i];
        }
        return nr/(n-2);
    }
};