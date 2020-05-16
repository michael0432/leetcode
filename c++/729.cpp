class MyCalendar {
public:
    vector<pair<int, int>> v;
    MyCalendar() {
        
    }
    
    bool book(int start, int end){
        for (int i = 0; i < v.size(); i++){
            if(start < v[i].second && end > v[i].first){
                return false;
            }
        }
        v.push_back({start, end});
        return true;
    }
};