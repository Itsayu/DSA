class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>s;
        int n=temperatures.size();
        vector<int>v;
        for(int i=n-1;i>=0;i--){
            while(s.empty()==false && s.top().first<=temperatures[i]){
                s.pop();
            }
            if(!s.empty()){
              v.push_back(s.top().second-i);
            }
            else{
                v.push_back(0);
            }
            s.push({temperatures[i],i});
        }
        reverse(v.begin(),v.end());
        return v;  
    }
};