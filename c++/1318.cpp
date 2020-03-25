class Solution {
public:
    int minFlips(int a, int b, int c) {
        int d = a | b;
        int e = d ^ c;
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
    }
};