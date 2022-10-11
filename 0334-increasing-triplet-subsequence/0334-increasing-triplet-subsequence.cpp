class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return false;
        int mn1=INT_MAX,mn2=INT_MAX;
        for(auto t:nums){
            if(t<=mn1)mn1=t;
            else if(t<=mn2)mn2=t;
            else return true;
        }
        return false;

    }
};