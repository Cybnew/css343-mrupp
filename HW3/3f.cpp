class MedianFinder {
public:
   // Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // Max Heap
    priority_queue<int, vector<int>, less<int>> maxHeap;
    
    // insert
    void addNum(int num) {
        // Balance smaller half and larger half.
        if (maxHeap.empty() || num > maxHeap.top()) {
            minHeap.emplace(num);
            if (minHeap.size() > maxHeap.size() + 1) {
                maxHeap.emplace(minHeap.top());
                minHeap.pop();
            }
        } else {
            maxHeap.emplace(num);
            if (maxHeap.size() > minHeap.size()) {
                minHeap.emplace(maxHeap.top());
                maxHeap.pop();
            }
        }
    }

    // Find Median
    double findMedian() {
        double median;
        if(minHeap.size()==maxHeap.size()){
            median = (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else{
            median = minHeap.top();
        }
       return median;
        
    }


 
};
