class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> sub_array;
        for (int i=0 ; i<s.size() ; i++){
            sub_array.push_back(abs(t[i] - s[i]));
        }
        int cost = sub_array[0], maxsum = 0;
        for (int l = 0, r = 0; r < s.size(); r++){
            if(cost <= maxCost){
                maxsum = max(r-l+1, maxsum);
            }
            else{
                cost -= sub_array[l];
                l++;
            }
            if(r+1 < s.size()) cost += sub_array[r + 1];
        }
        return maxsum;
    }
};