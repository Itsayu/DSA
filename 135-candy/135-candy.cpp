class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> l(n,1);
        vector<int> r(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                l[i]=l[i-1]+1;
            }
        }
        int ans=0;
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                r[i]=r[i+1]+1;
            }
            ans+=max(l[i],r[i]);
        }
        ans+=max(l[n-1],r[n-1]);
        return ans;
    }
};