class SmallestInfiniteSet {
    int curr = 1;
    bool removed[1001] = {};
public:
    SmallestInfiniteSet() {}
    
    int popSmallest() {
        while (removed[curr]) curr++;
        removed[curr] = true;
        return curr;
    }
    
    void addBack(int num) {
        if (num < curr) curr = num;
        removed[num] = false;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */