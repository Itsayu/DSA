class MyCalendar {
public:
    vector<vector<int>> v;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(int i=0;i<v.size();i++){
            if((start>=v[i][0] && start<v[i][1]) || (end>v[i][0] && end<=v[i][1]) || (start<v[i][0] && end>v[i][1])) return false;
        }
        v.push_back({start,end});
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */