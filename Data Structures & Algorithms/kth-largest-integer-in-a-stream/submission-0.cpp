class KthLargest {
public:
    priority_queue<int> heap;
    int k;
    KthLargest(int k, vector<int>& nums) {
       this->k = k;
       for (int i : nums) {
        this->heap.push(i);
       }
    }
    
    int add(int val) {
        vector<int> temp;
        this->heap.push(val);
        if (heap.size() < k) {
            return -1;
        } 
        for (int i = 0; i < k-1; i++) {
            temp.push_back(heap.top());
            heap.pop();
        }
        int t = heap.top();
        while(!temp.empty()) {
            this->heap.push(temp[0]);
            temp.erase(temp.begin());
        }
        return t;
    }
};
