class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, face = 0;
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int a = 0; a < 4; a++){
            for (int i = 0; i < instructions.size(); i++)
            {
                if (instructions[i] == 'R')
                {
                    face++;
                    face %= 4;
                }
                else if (instructions[i] == 'L')
                {
                    face += 3;
                    face %= 4;
                }
                else{
                    x += dir[face][0];
                    y += dir[face][1];
                }
            }

        }
        if(x == 0 && y == 0)
            return true;
        else
            return false;
    }
};