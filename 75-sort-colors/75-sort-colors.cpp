class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=(int)nums.size();
        int a = 0, r = 0, s = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)
                a++;
            else if(nums[i]==1)
                r++;
            else
                s++;
        }
        for(int i=0;i<a;i++)
            nums[i]=0;
        for(int i=a;i<a+r;i++)
            nums[i]=1;
        for(int i=a+r;i<n;i++)
            nums[i]=2;
    }
};