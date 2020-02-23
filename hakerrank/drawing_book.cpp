#include <iostream>
#include <vector>

using namespace std;

int solution(int n, int p){
    int flip_page, target_page;
    if(n % 2 == 0){
        flip_page = 2 + (n-2) / 2;
    }
    else{
        flip_page = 1 + (n-1) / 2;
    }
    flip_page -= 1;
    target_page = p / 2;
    return min(target_page, flip_page - target_page);
}

int main(){
    int n,p;
    cin >> n >> p;
    cout << solution(n,p) << endl;
}