class TimeMap {
public:
    map<int, multimap<string, string>> p;
    TimeMap() {
        
    }
    void set(string key, string value, int timestamp) {
        if (p.find(timestamp) != p.end()) {
            p.find(timestamp)->second.insert({key, value});
        } else {
            multimap<string, string> m;
            p.insert({timestamp, m});
            p.find(timestamp)->second.insert({key, value});
        }
    }
    
    string get(string key, int timestamp) {
        while (timestamp >= 0) {
            if (p.find(timestamp) != p.end()) {
                if (p.find(timestamp)->second.find(key) != p.find(timestamp)->second.end()) {
                    return p.find(timestamp)->second.find(key)->second;
                }
            }
            timestamp--;
        }
        return "";
    }
};
