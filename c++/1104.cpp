class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> output;
        while(label >= 1){
            output.push_back(label);
            label = label >> 1;
            int cnt = 0;
            for (int i = 31; i >= 0; i--){
                if((1 << i) & label){
                    cnt++;
                    if(cnt == 1)
                        continue;
                }
                if(cnt >= 1){
                    label = label ^ (1 << i);
                }
            }
            
        }
        reverse(output.begin(), output.end());
        return output;
    }
};