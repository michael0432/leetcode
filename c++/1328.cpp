class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size() <= 1)
            return "";
        
        bool b = true;
        for (int i = 0; i < palindrome.size(); i++){
            if(palindrome[i] != 'a'){
                if(palindrome.size() % 2 == 1 && i == (palindrome.size()-1)/2)
                    continue;
                else{
                    palindrome[i] = 'a';
                    b = false;
                    break;
                }
            }
        }
        if(b)
            palindrome[palindrome.size() - 1] = 'b';
        return palindrome;
    }
};