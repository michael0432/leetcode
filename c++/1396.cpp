class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> record;
    unordered_map<string, vector<int>> times;

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        record[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        times[record[id].first + stationName].push_back(t - record[id].second);
    }
    
    double getAverageTime(string startStation, string endStation) {
        int size = record[startStation + endStation].size();
        int sum = 0;
        for (int i = 0; i < size; i++){
            sum += record[startStation + endStation][i];
        }
        return (double)sum / size;
    }
};