#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

class Point{
public:
    double x;
    double y;
};

bool compare(const Point a, const Point b){
    return a.x < b.x;
}

double dis(Point a, Point b){
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

double closestPair(vector<Point>& p, int sid, int eid){
    
    if(sid >= eid)
        return 100000;
    if(eid - sid == 1)
        return dis(p[sid], p[eid]);

    int mid = (sid + eid) / 2;
    double left_min = closestPair(p, sid, mid);
    double right_min = closestPair(p, mid+1, eid);
    //cout << left_min << right_min << endl;
    double d = min(left_min, right_min);
    double line = (double)(p[mid].x + p[mid + 1].x) / 2;
    double mind = d;
    for (int i = mid + 1; p[i].x < line + d && i<=eid ; i++){
        for (int j = mid; p[j].x > line - d && j>=sid ; j--){
            mind = min(dis(p[i], p[j]), mind);
        } 
    }
    return mind;
}

int main(){
    int n;
    while(cin >> n && n != 0){
        
        vector<Point> p;
        for (int i = 0; i < n; i++){
            Point c;
            cin >> c.x >> c.y;
            p.push_back(c);
        }
        sort(p.begin(), p.end(), compare);
        
        double ans = closestPair(p, 0, p.size() - 1);
        if(ans <= 10000){
            printf("%.4lf\n", ans);
        }
        else{
            cout << "INFINITY" << endl;
        }
    }
}