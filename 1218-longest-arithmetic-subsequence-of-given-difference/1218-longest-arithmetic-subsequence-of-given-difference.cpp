class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
       unordered_map<int,int>m;
       int nr=0;
        for(int i=0;i<arr.size();i++){
            int c=arr[i];
            if(m.find(c-difference)!=m.end())
            m[c]=m[c-difference]+1;
            else
            m[c]=1;
            nr=max(nr,m[c]);
        }
        return nr;
    }
};