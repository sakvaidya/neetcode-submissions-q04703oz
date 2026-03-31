class MinStack {
public:
    map<int, int> hmap;
    stack<int> s;
    MinStack() {
    }
    
    void push(int val) {
        if (hmap.find(val) != hmap.end() && hmap.find(val)->second > 0) {
            hmap.find(val)->second++;
        } else {
            hmap.insert({val, 1});
        }
        s.push(val);
        
    }
    
    void pop() {
        int p;
        if (!s.empty()) {
            p = s.top();
            s.pop();
            if (hmap.find(p) != hmap.end() && hmap.find(p)->second <= 1) {
                hmap.erase(hmap.find(p));
            } else {
                if (hmap.find(p) != hmap.end()) {
                    hmap.find(p)->second--;
                }
            }
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        if (!hmap.empty()) {
            return hmap.begin()->first;
        }
    }
};
