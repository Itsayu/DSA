bool comp(pair<string, int>&p1, pair<string, int>& p2){
    if(p1.second==p2.second)
        return p1.first<p2.first;
    return p1.second>p2.second;
}
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int>m;
        for(int i=0; i<words.size(); i++){
            m[words[i]]++;
        }
        vector<pair<string, int>>v;
        for(auto it:m){
            v.push_back(make_pair(it.first, it.second));
        }
        sort(v.begin(), v.end(), comp);
        vector<string> res;
        for(int i=0; i<k; i++){
            res.push_back(v[i].first);
        }
        return (res);    
    }
};