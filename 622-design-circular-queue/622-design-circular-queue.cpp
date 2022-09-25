class MyCircularQueue {
public:
    vector<int> circularQueue;
    int insert= 0, size, front=0;
    
    MyCircularQueue(int k) {
       circularQueue.resize(k,-1);
        size= k;
    }
    
    bool enQueue(int value) {
        int insertAt= insert%size;
        if(circularQueue[insertAt]==-1){
            circularQueue[insertAt]= value; insert++;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(front==insert) return false;
        int removeFrom= front%size;
        circularQueue[removeFrom]= -1; front++;
        return true;
    }
    
    int Front() {
        return circularQueue[front%size];
    }
    
    int Rear() {
        if(insert==0) return -1;
        return circularQueue[(insert-1)%size];
    }
    
    bool isEmpty() {
        return front==insert;
    }
    
    bool isFull() {
        return insert-front==size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */