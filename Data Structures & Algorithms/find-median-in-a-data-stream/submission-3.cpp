class MedianFinder {
public:
    priority_queue<int> p;

    MedianFinder() {}
    
    void addNum(int num) {
        p.push(num);
    }
    
    double findMedian() {
        vector<int> v2;
        int totalSize = p.size();
        double result;

        if (totalSize % 2 == 0) {
            int targetIndex = (totalSize / 2) - 1; 
            
            for (int i = 0; i < targetIndex; i++) {
                v2.push_back(p.top());
                p.pop();
            }
            
            int m1 = p.top();
            v2.push_back(m1);
            p.pop();
            
            int m2 = p.top();
            result = (m1 + m2) / 2.0;
        } else {
            int targetIndex = totalSize / 2;
            
            for (int i = 0; i < targetIndex; i++) {
                v2.push_back(p.top());
                p.pop();
            }
            
            result = p.top();
        }

        for (int val : v2) {
            p.push(val);
        }

        return result;
    }
};