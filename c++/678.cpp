class Solution {
public:

    bool checkValidString(string s) {
        int left = 0, right = 0, star = 0;
        for (int i = 0; i < s.size(); i++){
            if(s[i] == '(')
                left++;
            if(s[i] == ')')
                right++;
            if(s[i] == '*')
                star++;
            if(left+star < right)
                return false;
        }
        left = 0, right = 0, star = 0;
        for (int i = s.size()-1; i >= 0; i--){
            if(s[i] == '(')
                left++;
            if(s[i] == ')')
                right++;
            if(s[i] == '*')
                star++;
            if(right+star < left)
                return false;
        }
        return true;
    }
};