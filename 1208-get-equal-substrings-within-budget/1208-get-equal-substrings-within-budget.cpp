class Solution {
public:
    int equalSubstring(string s, string t, int k) {
        int i=0,j=0,n=s.length(),z=0,sum=0,maxi=0;
        while(j<n)
        {
            int p=abs(s[j]-t[j]); 
            sum+=p;
            if(sum<=k) 
            {
                maxi=max(maxi,j-i+1);
                j++;
            }
            else if(sum>k)
            {
                while(sum>k)
                {
                    int p=abs(s[i]-t[i]);
                    sum-=p;
                    i++;
                }
                j++; 
            }
        }
        return maxi;
    }
};