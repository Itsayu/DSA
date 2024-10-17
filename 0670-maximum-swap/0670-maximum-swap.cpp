class Solution {
public:
    int maximumSwap(int num) {
        unordered_map<char,int>mp;
        string nums=to_string(num);
        string nums2=nums;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }

        sort(nums2.rbegin(),nums2.rend());
        int count=0;
        int i=0;

        while(count<1 && i<nums.size()){
            if(nums2[i]==nums[i]) i++;
            else{
                swap(nums[mp[nums2[i]]],nums[i]);
                count=1;
            }
        }

        return stoi(nums) ;

    }
};