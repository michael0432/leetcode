class Solution {
public:

    string entityParser(string text) {
        unordered_map<string, char> m = {{"&quot;", '\"'}, {"&apos;", '\''}, {"&amp;", '&'}, {"&gt;", '>'}, {"&lt;", '<'}, {"&frasl;", '/'}};
        string output, tmp;
        int idx = 0;
        bool flag = false;
        while(idx < text.size()){
            if(text[idx] == '&'){
                tmp += text[idx];
                flag = true;
            }
            else if(text[idx] == ';'){
                tmp += text[idx];
                cout << tmp << endl;
                if(m.count(tmp) != 0)
                    output += m[tmp];
                else
                    output += tmp;
                tmp = "";
                flag = false;
            }
            else if (flag){
                tmp += text[idx];
            }
            else{
                output += text[idx];
            }
            idx++;
        }
        return output;
    }
};