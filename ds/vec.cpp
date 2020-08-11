#include<iostream>

using namespace std;

struct returnType{
    int myInt;
    char myChar;
};

class myVector{
private:
    int curPos;
    int nowSize;
    int* arr;
    char* arrChar;
    int type;
    void addSize(){
        if(type == 0){
            int tmparr[nowSize*2];
            for(int i=0 ; i<curPos ; i++){
                tmparr[i] = arr[i];
            }
            arr = new int(nowSize*2);
            for(int i=0 ; i<curPos ; i++){
                arr[i] = tmparr[i];
            }
        }
        else{
            char tmparr[nowSize*2];
            for(int i=0 ; i<curPos ; i++){
                tmparr[i] = arrChar[i];
            }
            arrChar = new char(nowSize*2);
            for(int i=0 ; i<curPos ; i++){
                arrChar[i] = tmparr[i];
            }
        }
        
    }
public:
    myVector(string t){
        curPos = 0;
        nowSize = 1;
        if(t == "char") type = 1;
        else type = 0;
        arr = new int(1);
        arrChar = new char(1);
    }
    int size(){
        return curPos;
    }
    bool empty(){
        if(curPos == 0) return true;
        return false;
    }
    bool push_back(int a){
        if(type == 0){
            if(curPos == nowSize){
                addSize();
                arr[curPos] = a;
                curPos++;
            }
            else{
                arr[curPos] = a;
                curPos++;
            }
            return true;
        }
        return false;
    }
    bool push_back(char a){
        if(type == 1){
            if(curPos == nowSize){
                addSize();
                arrChar[curPos] = a;
                curPos++;
            }
            else{
                arrChar[curPos] = a;
                curPos++;
            }
            return true;
        }
        return true;
    }
    bool pop(){
        if(curPos == 0)
            return false;
        curPos--;
        return true;
    }
    bool find(int i){
        if(type == 0){
            for(int x=0 ; x<curPos; x++){
                if(arr[x] == i) return true;
            }
        }
        return false;
    }
    bool find(char i){
        if(type == 1){
            for(int x=0 ; x<curPos; x++){
                if(arrChar[x] == i) return true;
            }
        }
        
        return false;
    }
    returnType getElement(int i){
        returnType r;
        
        if(type == 0)
            r.myInt = arr[i];
        else
            r.myChar = arrChar[i];
        return r;
    }
};

int main(){
    myVector v("int");
    v.push_back(3);
    v.push_back(5);
    v.push_back(8);
    v.pop();
    cout << v.find(8) << endl;
    v.push_back(3);
    v.push_back(4);
    cout << v.getElement(3).myInt << endl;
}