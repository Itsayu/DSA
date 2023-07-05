class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> nr;
        
        for(auto x: nums){
            nr[x]++;
        }

        for(auto x: nr){
            if(x.second == 1){
                return x.first;
            }
        }
        
        return -1;
    }
};