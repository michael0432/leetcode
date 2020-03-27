#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <functional>

using namespace std;

struct pair_hash {
    template <class  T1, class  T2>
    size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};

using P = pair<string, string>;

int main(){
    int n;
    cin >> n;
    unordered_map<P, int, pair_hash> m;
    map<string, int> m2;
    for(int i=0 ; i<n ; i++){
        string line;
        string country;
        string name = "";
        string token;
        getline(cin, line);
        int cnt = 0;
        size_t pos = 0;
        string delimiter = " ";
        while ((pos = line.find(delimiter)) != std::string::npos) {
            cout << token << endl;
            if(cnt == 0) country = token;
            else name += token;
            token = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
            cnt += 1;
        }
        //cout << country << name << endl;
        if(m.count({country, name}) != 0){
            m[{country, name}] += 1;
        }
        else{
            m[{country, name}] = 1;
        }
    }
    for(auto it=m.begin(); it!=m.end() ; it++){
        if(m2.count(it->first.first) != 0){
            m2[it->first.first] += it->second;
        }
        else{
            m2[it->first.first] = it->second;
        }
    }
    for(auto it=m2.begin() ; it!=m2.end() ; it++){
        cout << it->first << " " << it->second << endl;
    }
}