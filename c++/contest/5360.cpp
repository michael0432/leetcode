class Solution {
public:

    int getTotal(int n){
        int total = 0;
        while(n > 0){
            total += n % 10;
            n /= 10;
        }
        return total;
    }

    int countLargestGroup(int n) {
        unordered_map<int, int> m;
        int largeset = 0;
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            int g = getTotal(i);
            if(m.count(g))
                m[g]++;
            else{
                m[g] = 1;
            }
            largeset = max(largeset, m[g]);
        }
        for (auto it = m.begin(); it != m.end(); it++){
            if(it->second == largeset)
                cnt++;
        }
        return cnt;
    }
};