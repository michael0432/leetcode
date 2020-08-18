#include <iostream>
#include <vector>

using namespace std;

template <class T, int N>
class mysequence {
private:
    T memblock [N];
public:
    void setmember (int x, T value){
        memblock[x] = value;
    }
    T getmember (int x){
        return memblock[x];
    }
};

int main(){
    mysequence<int, 5> myints;
    mysequence <double,5> mydoubles;
    myints.setmember (0,100);
    mydoubles.setmember (3,3.1416);
    cout << myints.getmember(0) << endl;
    cout << mydoubles.getmember(3) << endl;
}