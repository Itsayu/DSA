class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int low=0,high=matrix.size()*matrix[0].size()-1,mid;        
//         int n=matrix[0].size();
//         while(low<=high){
//             mid=(low+high)/2;
//             int mid_element=matrix[mid/n][mid%n];
//             if(target==mid_element) 
//                 return true;
//             else if(target<mid_element)high=mid-1;
//             else if(target>mid_element) low=mid+1; 
//         }
//         return false;
        
    int row = matrix.size();
    int col = matrix[0].size();
    
    int start = 0;
    int end = row*col-1;
    
    int mid = start + (end-start)/2;
    
    while(start <= end){
        int searchedElement = matrix[mid/col][mid%col];
        
            if(searchedElement == target){
                return 1;
            }
        
            if(searchedElement < target){
                start = mid+1;
            }
        
            else{
                end = mid-1;
            }
            mid = start + (end-start)/2; 
        }
        return 0;
    }
};