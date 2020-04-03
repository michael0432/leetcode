class Solution {
public:
    unordered_set<int> set;
    bool isHappy(int n) {
        if(n == 1)
            return true;
        if(set.count(n) != 0)
            return false;
        else{
            set.insert(n);
            return isHappy(count_num(n));
        }
    }

    int count_num(int n){
        int cnt = 0;
        while(n > 0){
            cnt += (n % 10) * (n % 10);
            n = n / 10;
        }
        return cnt;
    }
};