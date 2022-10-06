class TimeMap {
    unordered_map<string, vector<pair<int,string>>> hash;
public:
    TimeMap() {        
    }
    
    void set(string key, string value, int timestamp) {
        hash[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(hash[key].size()==0) return "";
        if(hash[key][0].first > timestamp) return "";
        for(int i=hash[key].size()-1; i>=0; i--) {
            if(hash[key][i].first <= timestamp) {
                return hash[key][i].second;
            }
        }
        return "";  
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */