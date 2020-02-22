#include <unordered_map>
#include <queue>

using namespace std;

class LRUCache {
public:
    int cap;
    unordered_map<int,pair<int,int>> m;
    deque<int> q;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        cout << "get:" << key << endl;
        if(m.count(key) == 0)
            return -1;
        else{
            //cout << "first:" << key << " " << m[key].second << endl;
            q.erase(q.begin() + m[key].second);
            q.push_back(key);
            m[key] = {m[key].first, q.size() - 1};
            //cout << "last:" << key << " " << m[key].second << endl;
            printq();
            return m[key].first;
        }
        
    }
    
    void put(int key, int value) {
        cout << "put:" << key << ", " << value << endl;
        if(m.count(key) == 0){
            if(q.size() >= cap){
                m.erase(q.front());
                q.pop_front();
            }
            q.push_back(key);
            m[key] = {value,q.size()-1};
        }
        else{
            q.erase(q.begin() + m[key].second);
            q.push_back(key);
            m[key] = {value, q.size() - 1};
        }
        printq();
    }

    void printq(){
        for (int i = 0; i < q.size(); i++){
            cout << q[i] << " ";
        }
        cout << endl;
        for (auto it = m.begin(); it != m.end(); it++){
            cout << "map:" << it->first << ", " << it->second.first << ", " << it->second.second;
        }
        cout << endl;
    }
};