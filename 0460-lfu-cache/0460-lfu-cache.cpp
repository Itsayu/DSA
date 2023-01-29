class LFUCache {
public:
    public:

    unordered_map<int, list<int> > freqMap;
    unordered_map<int, pair <list <int>::iterator, int> > key_Node;

    unordered_map<int, int> counter;
    int lowFreq = 1;
    int cap = 0;


    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(key_Node.find(key) != key_Node.end() ){
            int freq = counter[key];
            freqMap[freq].erase(key_Node[key].first);
            freq++;
            freqMap[freq].push_front(key);
            key_Node[key] = {freqMap[freq].begin(), key_Node[key].second};
            counter[key]++;
            return key_Node[key].second;
        }
        return -1;  
    }
    
    void put(int key, int value) {
      if(cap == 0){
        return;
      }
        int freq = counter[key];

        if(key_Node.find(key) != key_Node.end() ){
            freqMap[freq].erase(key_Node[key].first);
        }
        else if(key_Node.size() == cap){
          while(freqMap[lowFreq].empty() ){
              lowFreq++;
          }
          int topN = freqMap[lowFreq].back();
          key_Node.erase(topN);
          counter.erase(topN);
          freqMap[lowFreq].pop_back();
        }
          freq++;
          freqMap[freq].push_front(key);
          key_Node[key] = {freqMap[freq].begin(), value};
          counter[key]++;
          if(freq<lowFreq){
            lowFreq = freq;
          }
          
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */