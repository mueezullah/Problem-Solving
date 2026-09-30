class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minHeap.push(num);

        maxHeap.push(minHeap.top());
        minHeap.pop();

        if(maxHeap.size() - minHeap.size() > 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()){
            double mean = (maxHeap.top() + minHeap.top()) / 2.0;
            return mean;
        }
        
        else return maxHeap.top();
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */