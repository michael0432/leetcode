class Solution {
public:

    void moveUD(int ud, string& s){
        if(ud < 0){
            for (int x = 0; x < -ud; x++)
                s += "U";
        }
        else{
            for (int x = 0; x < ud; x++)
                s += "D";
        }
    }
    void moveLR(int lr, string& s){
        if(lr < 0){
            for (int x = 0; x < -lr; x++)
                s += "L";
        }
        else{
            for (int x = 0; x < lr; x++)
                s += "R";
        }
    }

    string alphabetBoardPath(string target) {
        vector<pair<int, int>> map;
        pair<int, int> pos = {0,0};
        string s;
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                map.push_back({i, j});
            }
        }
        map.push_back({5, 0});

        for (int i = 0; i < target.size(); i++){
            int lr = map[target[i] - 'a'].second - pos.second;
            int ud = map[target[i] - 'a'].first - pos.first;
            pos = map[target[i] - 'a'];
            if(target[i] == 'z'){
                moveLR(lr, s);
                moveUD(ud, s);
            }
            else{
                moveUD(ud, s);
                moveLR(lr, s);
            }
            
            
            s += "!";
        }
        return s;
    }
};