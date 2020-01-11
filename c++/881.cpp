#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int cnt = 0;
        int pass_people = 0;
        int front_idx = 0;
        int back_idx = people.size()-1;
        while(pass_people < people.size()){
            if((limit - people[back_idx]) >= people[front_idx]){
                front_idx += 1;
                back_idx -= 1;
                pass_people += 2;
            }
            else{
                back_idx -= 1;
                pass_people += 1;
            }
            cnt += 1;
        }
        return cnt;
    }
};

int main(){
    vector<int> people = {3,2,2,1};
    int limit = 3;
    Solution s;
    // s.numRescueBoats(people, limit);
    cout << s.numRescueBoats(people, limit) << endl;
}