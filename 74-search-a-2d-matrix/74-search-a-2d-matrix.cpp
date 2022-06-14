class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0,high=matrix.size()*matrix[0].size()-1,mid;        
        int n=matrix[0].size();
        while(low<=high){
            mid=(low+high)/2;
            int mid_element=matrix[mid/n][mid%n];
            if(target==mid_element) 
                return true;
            else if(target<mid_element)high=mid-1;
            else if(target>mid_element) low=mid+1; 
        }
        return false;

    }
};