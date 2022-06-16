class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<2) return s;
        int mxlen=1,idx=0;
        int left,right;
        for(int i=0;i<n;i++){
            left=i-1,right=i+1;
            while(left>=0 && s[i]==s[left])
                left--;
            while(right<n && s[i]==s[right])
                right++;    
            while(left>=0 && right<n && s[left]==s[right]){
                left--;
                right++;
            }
            int len=right-left-1;
            if(len>mxlen){
                mxlen=len;
                idx=left+1;
            }
        }
        return s.substr(idx,mxlen);
    }
};