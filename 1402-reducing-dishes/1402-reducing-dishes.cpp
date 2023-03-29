class Solution {
public:
    int maxSatisfaction(vector<int>& v){
        int sum=0, temp=0, count=0, ans=0;
        sort(v.begin(), v.end());
        
        for(int i=0; i<v.size(); i++){
            if(v[i] >= 0) {
                temp=i;
                break;
            }
            count++;
        }
        count = count+1;
        int time;
        while(count--) {
            time=sum=0;
            for(int j=temp; j<v.size(); j++){
                time++;
                sum = sum+(v[j]*time);
            }
            ans = max(ans,sum);
            temp--;
        }
        
        return ans;  
    }
};