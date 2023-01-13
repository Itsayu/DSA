class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>m;
        set<int>st;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        for( auto i : m){
            st.insert(i.second);
        }
       if(m.size()==st.size()){
           return true;
       }
        return false;
    }
};