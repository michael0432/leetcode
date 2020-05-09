class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int shiftl = 0;
        string output = s;
        for (int i = 0; i < shift.size(); i++){
            if(shift[i][0] == 0){
                shiftl -= shift[i][1];
            }
            else{
                shiftl += shift[i][1];
            }
        }
        shiftl %= s.size();
        if(shiftl < 0)
            shiftl += s.size();
        
        for (int i = 0; i < s.size();i++){
            output[(i+shiftl) % s.size()] = s[i];
        }
        
        return output;
    }
};