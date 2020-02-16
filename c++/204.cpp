class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        for (int i = 1; i < n; i++){
            if(i == 2)
                cnt += 1;
            else if(isPrime(i) && i != 1)
                cnt += 1;
            
        }
        return cnt;
    }
    bool isPrime(int prime){
        for (int i = 2; i*i <= prime; i++){
            if(prime % i == 0)
                return false;
        }
        return true;
    }   
};