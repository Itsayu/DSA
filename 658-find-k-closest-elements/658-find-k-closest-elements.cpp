class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
        // for(auto i:arr){
        //     p.push(make_pair(abs(i-x),i));
        // }
        // vector<int> ans;
        // while(k--){
        //     ans.push_back(p.top().second);
        //     p.pop();
        // }
        // sort(ans.begin(),ans.end());
        // return ans;
        
        int l = 0;
       int r = arr.size() - k;

       while (l < r) {
         const int m = (l + r) / 2;
         if (x - arr[m] <= arr[m + k] - x)
           r = m;
         else
           l = m + 1;
       }

       return {begin(arr) + l, begin(arr) + l + k};
    }
};