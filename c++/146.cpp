class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if(it == m.end())
            return -1;
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if(it != m.end()){
            cache.erase(it->second);
        }
        cache.push_front({key, value});
        m[key] = cache.begin();
        if(m.size() > cap){
            int x = cache.rbegin()->first;
            cache.pop_back();
            m.erase(x);
        }
            
    }
private:
    int cap;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */