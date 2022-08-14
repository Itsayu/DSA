// --------------LINER SEARCH---------------
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//      for(int i=0; i<nums.size(); i++){
//             if(nums[i]==target){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

// ----------------------BINARY SSEARCH----------------------

class Solution {
public:
    int search(vector<int>& nums, int target){
        
        int n = nums.size()-1;
        int low = 0;
        int high = n;
        
        while (low <= high){
            // int mid = (low + high) / 2;
            int mid = low + (high - low) / 2;
            
            if(nums[mid]==target){
                return mid;
            }
            else if(target < nums[mid]){
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return -1;
    }
};