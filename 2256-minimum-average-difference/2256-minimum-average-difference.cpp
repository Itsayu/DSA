class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int length = nums.size();
        long arr[length];
        long sum = 0;
        for(int i=0;i<length;i++){
            sum+=nums[i];
        }
        arr[0]=nums[0];
        for(int i=1;i<length;i++){
            arr[i]=arr[i-1]+nums[i];
        }
        int result[length];
        for(int i=0;i<length-1;i++){
            int p1 = arr[i]/(i+1);
            int p2 = (sum - arr[i])/(length-i-1);
            result[i] = p1-p2;
            result[i] = abs(p1-p2);
        }
        result[length-1] = sum/length;
        int min = result[0];
        int index=0;
        for(int i=0;i<length;i++){
            if(min>result[i]){
                min=result[i];
                index=i;
            }
        }
        return index;   
    }
};