#include <iostream>
#include <string>

using namespace std;

int dis(int a, int b){
    if(a > b) return a-b;
    else return b-a;
}

string solution(int cata, int catb, int mouse){
    int disa = dis(cata, mouse), disb = dis(catb, mouse);
    if(disa > disb){
        return "Cat B";
    }
    else if(disa < disb){
        return "Cat A";
    }
    else{
        return "Mouse C";
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=0 ; i<n ; i++){
        int x,y,z;
        cin >> x >> y >> z;
        cout << solution(x,y,z) << endl;
    } 
}