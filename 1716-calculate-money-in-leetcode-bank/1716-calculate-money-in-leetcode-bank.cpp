class Solution {
public:
    int solve(int week){
        int result=0;
           for(int i=0;i<week;i++){
               result+=28+(i*7);
           }
           return result;
    }
    int totalMoney(int n) {
       int week=n/7;
       int ans=solve(week);
       int day=n%7;
       if(day==0){
           return ans;
       }
       else{
           week++;
           while(day--){
               ans+=week++;
           }
       }
       return ans;
    }
};