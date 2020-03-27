class Solution {
public:
    int minFlips(int a, int b, int c) {
        int d = a | b;
        int e = d ^ c;
<<<<<<< HEAD
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
=======
        int ans = 0;
        for(int i=0 ; i<32 ; i++){
            if((1<<i) & e){
                ans++;
                if(((1<<i) & a) && ((1<<i) & b)){
                    ans++;
                }
            }
            
        }
        return ans;
>>>>>>> e138063231ed70c87487db22ec8c76acdebfd56e
    }
};