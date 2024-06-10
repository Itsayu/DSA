class Solution {
public:
    int heightChecker(vector<int>& h) {
     vector<int> a=h;
     int k=0;
     sort(a.begin(),a.end());
     for(int i=0;i<a.size();i++){
         k+=(a[i]!=h[i]);
     }
     return k;
    }
};