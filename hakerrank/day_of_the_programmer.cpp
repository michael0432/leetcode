#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(int year){
    
    int target_day = 13;
    int target_month = 9;
    string target_months = "";
    string target_days = "";
    if(year <= 1917){
        if(year % 4 == 0){
            //229
            target_day -= 1;
        }
    }
    else if(year == 1918){
        target_month = 9;
        target_day = 26;
    }
    else{
        if(year % 400 == 0){
            target_day -= 1;
        }
        else if(year % 4 == 0 && year % 100 != 0){
            target_day -= 1;
        }
    }
    if(target_month < 10){
        target_months = "0"+to_string(target_month);
    }
    else{
        target_months = to_string(target_month);
    }
    if(target_day < 10){
        target_days = "0"+to_string(target_day);
    }
    else{
        target_days = to_string(target_day);
    }
    return target_days + "." + target_months + "." + to_string(year);
}

int main(){
    int year;
    cin >> year;
    cout << solution(year);
}