class Solution {
public:
    
    
    int getKth(int lo, int hi, int k) {
        unordered_map<int,int> mem;
        vector<pair<int,int>> v;
        for(int i=lo ; i<=hi ; i++){
            
            int num = i;
            int cnt = 0;
            while(num != 1){
                if(mem.count(num) != 0){
                    cnt += mem[num];
                    break;
                }
                if(num % 2 == 0){
                    num = num / 2;
                }
                else{
                    num = 3 * num + 1;
                }
                cnt ++;
            }
            mem[num] = cnt;
            
            v.push_back({i,cnt});
        }
        sort(v.begin(), v.end(), [](const pair<int, int> &a, pair<int, int> &b) {
            if(a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });
        
        return v[k-1].first;
    }
};