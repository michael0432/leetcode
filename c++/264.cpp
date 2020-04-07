class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v = {1};
        
        int two_idx = 0, three_idx = 0, five_idx = 0;
        while(v.size() < n){
            int tw = v[two_idx] * 2;
            int thr = v[three_idx] * 3;
            int fi = v[five_idx] * 5;
            int min_n = min(tw, min(thr, fi));
            if(tw == min_n){
                two_idx++;
            }
            else if(thr == min_n){
                three_idx++;
            }
            else if(fi == min_n){
                five_idx++;
            }
            if(min_n != v[v.size()-1]) v.push_back(min_n);
            //cout << v[v.size()-1] << endl;
        }
        return v[n - 1];
    }
};