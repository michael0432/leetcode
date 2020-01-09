#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int magicalString(int n){
        vector<int> v = {1,2,2};
        int idx = 1;
        int count = 0;
        while(v.size() < n){
            if(v[idx+1] == 2 && v[v.size()-1] == 2){
                // two 1
                v.push_back(1);
                v.push_back(1);
                //count += 2;
            }
            else if(v[idx+1] == 1 && v[v.size()-1] == 1){
                // one 2
                v.push_back(2);
            }
            else if(v[idx+1] == 1 && v[v.size()-1] == 2){
                // one 1
                v.push_back(1);
                //count += 1;
            }
            else if(v[idx+1] == 2 && v[v.size()-1] == 1){
                // two 2
                v.push_back(2);
                v.push_back(2);
                // count += 1;
            } 
            idx += 1;
        }
        for(int i=0 ; i < n ; i++){
            if(v[i] == 1){
                count += 1;
            }
        }
        return count;
    }
    
};

int main(){
    Solution s;
    // s.magicalString(10);
    cout << s.magicalString(4) << endl;
}