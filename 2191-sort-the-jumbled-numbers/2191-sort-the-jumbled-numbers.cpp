class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int>ans;
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            int m=0;
            int j=0;
            while(n!=0){ 
                int d=n%10;
                m+=mapping[d]*pow(10,j);
                n/=10;
                j++;
            }      
            if(nums[i]==0)
                m=mapping[0];
            v.push_back({m,i});
        }
        sort(v.begin(),v.end());
        for(auto p:v){
            ans.push_back(nums[p.second]);
        }
        return ans;
    }
};