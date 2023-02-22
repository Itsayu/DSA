class Solution {
public:
    bool valid(vector<int>& weights, int&D, int m){
        int sum=0, days=1;
        for(int i:weights){
            sum += i;
            if(sum>m){
                sum=i;
                days++;
            }
            if(days>D) return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0, maxi=INT_MIN;
        for(int i:weights){
            sum += i;
            maxi = max(maxi, i);
        }
        int n=weights.size();
        if(days==1) return sum;
        if(days==n) return maxi;
        int l=maxi, r=sum, ret;
        while(l<=r){
            int m=l+(r-l)/2;
            if(valid(weights, days, m)){
                ret=m;
                r=m-1;
            }
            else l=m+1;
        }
        return ret; 
    }
};