#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int,bool> map;
    int cnt = 0;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        visit(rooms,0);
        if(cnt >= rooms.size()) return true;
        else return false;
    }
    void visit(vector<vector<int>>& rooms, int number){
        if(map.count(number) == 0){
            cnt += 1;
            map[number] = true;
            for(int i=0 ; i<rooms[number].size() ; i++){
                visit(rooms, rooms[number][i]);
            }
        }
        if(cnt >= rooms.size()) return;
        return;
    }
};

int main(){
    vector<vector<int>> v = {{},{2},{1}};
    Solution s;
    cout << s.canVisitAllRooms(v) << endl;
}