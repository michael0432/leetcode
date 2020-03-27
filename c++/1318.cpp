class Solution {
public:
    int minFlips(int a, int b, int c) {
        int d = a | b;
        int e = d ^ c;
        int total_dif = 0;
        int total_one = 0;
        for (int i = 0; i < 31; i++){
            if(e & (1<<i)){
                total_dif++;
            }
            if(d & (1<<i)){
                total_one++;
            }
        }
        return total_dif + (total_dif - total_one);
    }
};