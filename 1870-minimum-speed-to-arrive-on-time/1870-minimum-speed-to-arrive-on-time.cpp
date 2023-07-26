class Solution {
public:
    bool helper(vector<int>&dist,int speed,double hour){
        double ans=0;
        int n= dist.size();
        for(int i=0; i<n-1; i++){
            if(dist[i]%speed==0){
                ans+= dist[i]/speed;
            }
            else{
                ans+= (dist[i]/speed)+1;
            }
        }
        ans+= (double)(dist[n-1])/(double)(speed);
        if(ans>hour) return false;
        return true;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int ans=-1;
        int hi=1e7;
        int n= dist.size();  
        int lo= 1;
        while(lo<=hi){
            int mid= (lo+hi)/2;
            if(helper(dist,mid,hour)){
                ans= mid;
                hi= mid-1;
                
            }
            else{
                lo= mid+1;
            }
            
         }
        return ans;   
    }
};