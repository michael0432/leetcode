#include <iostream>

using namespace std;

void print(string s){
    cout<<"String!"<<endl;
}

void print(int i){
    cout<<"Int!"<<endl;
}

void print(double d){
    cout<<"Double!"<<endl;
}

int main(){
	print("123");
	print(1);
	print(1.3);
}