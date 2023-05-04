class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        vector<int> v(max(nums1.size(), nums2.size()));
        vector<int>::iterator it, ls;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        ls = set_intersection(nums1.begin(), nums1.end(),nums2.begin(), nums2.end(), v.begin());
        set<int> s;
        for(it = v.begin(); it != ls; ++it){
            s.insert(*it);
        }
        v.clear();
        for(auto i : nums1){
            if(s.find(i) == s.end()){ 
                v.push_back(i);
                s.insert(i);
            }
        }
        ans.push_back(v);
        v.clear();
        for(auto i : nums2){
            if(s.find(i) == s.end()){ 
                v.push_back(i);
                s.insert(i);
            }
        }
        ans.push_back(v);
        return ans;
    }
};