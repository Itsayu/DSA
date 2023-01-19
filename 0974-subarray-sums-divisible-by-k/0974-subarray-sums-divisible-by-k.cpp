class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int presum=0;
        int ans=0;
        map<int, int> nr;
        nr.insert({0,1}); 
        for(int i=0; i<n; i++){
            presum += nums[i];
            int temp=presum%k;
            if(temp<0){
                temp += k;
            }
            if(nr.find(temp) != nr.end()){
                ans += nr[temp];
                nr[temp]++;   
            }
            else
                nr[temp]=1;
        }
        return ans;
    }
};