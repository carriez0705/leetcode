bool comp(int a, int b){
    return a>b;
}
class MedianFinder {
    vector<int> smallHalf;
    vector<int> largeHalf;
public:
    MedianFinder(){
        smallHalf.clear();
        largeHalf.clear();
    }
    // Adds a number into the data structure.
    void addNum(int num) {
        if(smallHalf.size() && num<smallHalf.front()){
            if(smallHalf.size()<=largeHalf.size()){
                smallHalf.push_back(num);
                push_heap(smallHalf.begin(), smallHalf.end());
            }
            else{
                pop_heap(smallHalf.begin(), smallHalf.end());
                int n = smallHalf.back();
                smallHalf.pop_back();
                largeHalf.push_back(n);
                push_heap(largeHalf.begin(), largeHalf.end(), comp);
                smallHalf.push_back(num);
                push_heap(smallHalf.begin(), smallHalf.end());
            }
        }
        else if(largeHalf.size() && num>largeHalf.front()){
            if(largeHalf.size()<=smallHalf.size()){
                largeHalf.push_back(num);
                push_heap(largeHalf.begin(), largeHalf.end(), comp);
            }
            else{
                pop_heap(largeHalf.begin(), largeHalf.end(), comp);
                int n = largeHalf.back();
                largeHalf.pop_back();
                smallHalf.push_back(n);
                push_heap(smallHalf.begin(), smallHalf.end());
                largeHalf.push_back(num);
                push_heap(largeHalf.begin(), largeHalf.end(), comp);
            }
        }
        else{
            if(smallHalf.size()<largeHalf.size()){
                smallHalf.push_back(num);
                push_heap(smallHalf.begin(), smallHalf.end());
            }
            else{
                largeHalf.push_back(num);
                push_heap(largeHalf.begin(), largeHalf.end(), comp);
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(!smallHalf.size() && !largeHalf.size())
            return -1;
        if(smallHalf.size()==largeHalf.size())
            return 0.5*(smallHalf.front()+largeHalf.front());
        else if(smallHalf.size()>largeHalf.size())
            return smallHalf.front();
        else
            return largeHalf.front();
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
