class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        if(n%2)
            return {};
        vector<int>v;
        sort(changed.begin(),changed.end());
        unordered_map<int, int>ayu;
        for(auto &i: changed)
            ayu[i]++;
        for(int i=0; i<n; i++){
            if(ayu[changed[i]]==0) 
                continue;
            if(ayu[changed[i]*2]==0)
                return {};
            ayu[changed[i]*2]--;
            ayu[changed[i]]--;
            v.push_back(changed[i]);
        }
        return v;
    }
};