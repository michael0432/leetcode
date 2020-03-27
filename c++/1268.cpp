class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<string> v;
        vector<vector<string>> output(searchWord.size(),v);
        int sid=0, eid=products.size()-1;
        for(int i=0 ; i<searchWord.size() ; i++){
            int first = -1, end=-1;
            for(int j=sid ; j<=eid ; j++){
                if(products[j][i] == searchWord[i]){
                    if(first == -1) first = j;
                    if(output[i].size() < 3) output[i].push_back(products[j]);
                    end = j;
                }
            }
            sid = first;
            eid = end;
            if(sid > eid || eid == -1) break;
        }
        return output;
    }
};