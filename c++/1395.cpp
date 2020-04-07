class Solution {
public:
    int numTeams(vector<int>& rating) {
        int cnt = 0;
        for (int i = 0; i < rating.size(); i++){
            for (int j = i+1; j < rating.size(); j++){
                for (int k = j+1; k < rating.size(); k++){
                    if((rating[k] > rating[j] && rating[j] > rating[i]) || (rating[k] < rating[j] && rating[j] < rating[i])){
                        cout << rating[i] << " " << rating[j] << " " << rating[k] << endl;
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int cnt = 0;
        for (int j = 1; j < rating.size()-1; j++){
            int left_cnt = 0;
            int right_cnt = 0;
            for (int i = j - 1; i >= 0; i--){
                if(rating[i] < rating[j])
                    left_cnt++; 
            }
            for (int k = j + 1; k < rating.size();k++){
                if(rating[k] > rating[j])
                    right_cnt++;
            }
            cnt += left_cnt * right_cnt + (j - left_cnt) * (rating.size() - j - 1 - right_cnt);
        }
        return cnt;
    }
};