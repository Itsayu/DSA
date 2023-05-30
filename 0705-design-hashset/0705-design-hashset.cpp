class MyHashSet {
public:
    bitset<1000001> table;
    MyHashSet() {
        table.reset();
    }
    
    void add(int key) {
        table.set(key);
    }
    
    void remove(int key) {
        table.set(key, 0);
    }
    
    bool contains(int key) {
        return table[key];
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */