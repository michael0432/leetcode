#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int solution(string input){
    string numbers = "0123456789";
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special_characters = "!@#$%^&*()-+";
    int sub_len = max((6 - (int)input.length()), 0);
    int digit_num = 0, lowercase_num = 0, uppercase_num = 0, special_char_num = 0;
    int sub_digit_num, sub_lowercase_num, sub_uppercase_num, sub_special_char_num;
    for (int i = 0; i < input.size(); i++){
        if(input[i] - '0' <=9 && input[i] - '0' >= 0)
            digit_num += 1;
        else if(input[i] - 'a' <=25 && input[i] - 'a' >= 0)
            lowercase_num += 1;
        else if(input[i] - 'A' <=25 && input[i] - 'A' >= 0)
            uppercase_num += 1;
        else if(find(special_characters.begin(), special_characters.end(), input[i]) != special_characters.end())
            special_char_num += 1;
    }
    sub_digit_num = max((1 - digit_num), 0);
    sub_lowercase_num = max((1 - lowercase_num), 0);
    sub_uppercase_num = max((1 - uppercase_num), 0);
    sub_special_char_num = max((1 - special_char_num), 0);
    int total = sub_digit_num + sub_lowercase_num + sub_uppercase_num + sub_special_char_num;
    total = max(total, sub_len);
    return total;
}

int main(){
    int n;
    string input;
    cin >> n >> input;
    cout << solution(input);
}