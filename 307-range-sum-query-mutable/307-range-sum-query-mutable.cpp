class NumArray {
public:
    vector<int> arr;
    vector<int> seg;
    
    void build(int l, int r, int index){
        if(l == r){
            seg[index] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, (index * 2) + 1); 
        build(mid + 1, r, (index * 2 )+ 2);
        seg[index] = seg[(index * 2) + 1] + seg[(index * 2 )+ 2];
    }
    
    int getSum(int node,int sl, int sr, int l, int r){
        if(sl >= l && sr <= r ){
            return seg[node];
        }
        if(sr < l || sl > r){
            return 0;
        }
        int mid = (sl + sr) / 2;
        return getSum(2 * node + 1, sl, mid, l, r) + getSum(2 * node + 2, mid + 1, sr, l, r);
    }
    
    void updateSegTree(int si, int sl, int sr, int pos, int diff){
        if(pos < sl || pos > sr){
            return;
        }
        seg[si] += diff;
        if(sl != sr){
            int mid = (sl + sr) / 2;
            updateSegTree(si * 2 + 1, sl , mid, pos, diff);
            updateSegTree(si * 2 + 2, mid + 1, sr, pos, diff);
        }
    }
    
    NumArray(vector<int>& nums) {
        arr = nums;
        seg = vector<int>(4* arr.size(), 0);
        build(0, arr.size() - 1 , 0);
    }
    
    void update(int index, int val) {
        int diff = val - arr[index];
        arr[index] = val;
        updateSegTree(0, 0, arr.size() - 1, index, diff);
    }
    
    int sumRange(int left, int right) {
        return getSum(0, 0, arr.size() - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */