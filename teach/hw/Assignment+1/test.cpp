#include <vector>
#include <iostream>

using namespace std;

int main(){
    vector<int> v(198,0);
    cout << v.size() << " "<< v.capacity() << endl;
    v.resize(199);
    cout << v.size() << " "<< v.capacity() << endl;
    // for(int i=0; i<30; i++){
    //     cout << v.size() << " "<< v.capacity() << endl;
    //     v.push_back(i);
    // }
}