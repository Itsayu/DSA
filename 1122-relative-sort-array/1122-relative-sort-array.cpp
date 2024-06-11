class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        map<int, int> nr;
        for(auto x: arr1)
            nr[x]++;
        for(auto y: arr2){
            if(nr.find(y) != nr.end()){
                auto x = nr.find(y);
                int count = x -> second;
                vector<int>v(count, y);
                ans.insert(ans.end(), v.begin(), v.end());
                nr.erase(x);
            }
        }
        for(auto x : nr){
            int element = x.first;
            int count = x.second;
            vector<int>v(count, element);
            ans.insert(ans.end(), v.begin(), v.end());
        }
        return ans;
    }
};