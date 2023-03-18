class BrowserHistory {
public:
    vector<string>v;
int curr, cnt = 0;
    BrowserHistory(string homepage) {
     
        v.push_back(homepage);
        curr = 0;
    }
    
    void visit(string url) {
     
      curr++;
      v.resize(curr);
      v.push_back(url); 
    }
    
    string back(int steps) {
     
     curr = max(0, curr - steps);
     return v[curr];
    }
    
    string forward(int steps) {
     int n = v.size();
     curr = min(n-1, curr+steps);

     return v[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */