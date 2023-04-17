class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res(candies.size(),false);
        int highest=INT_MIN;
        for(int i=0;i<candies.size();i++){
            highest=max(candies[i],highest);
        }
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=highest){
                res[i]=true;
            }
        }
        return res;
    }
};