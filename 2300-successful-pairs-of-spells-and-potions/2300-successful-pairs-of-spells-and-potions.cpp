class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans;
        int n=potions.size();
        for(int i=0;i<spells.size();i++){
            int l=0;
            int r=potions.size()-1;
            //Binary Search to track from where product is greater than success
            while(r>=l){
                int mid=l+(r-l)/2;
                long long temp = ((long long)(potions[mid])*spells[i]);
                if(temp>=success)
                    r=mid-1;
                else
                    l=mid+1;
            }
            
            ans.push_back(n-l);
        }
        return ans; 
    }
};