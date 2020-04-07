class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int circle_max_x = x_center + radius;
        int circle_max_y = y_center + radius;
        int circle_min_x = x_center - radius;
        int circle_min_y = y_center - radius;
        double center_x = (double)(x1 + x2) / 2;
        double center_y = (double)(y1 + y2) / 2;
        double cross = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) / 2;

        if(sqrt((x_center - center_x) * (x_center - center_x) + (y_center - center_y) * (y_center - center_y)) > (radius + cross))  
            return false;
        if(x1 <= circle_max_x && x2 >= circle_min_x){
            if(y1 <= circle_max_y && y2 >= circle_min_y){
                return true;
            }
        }
        return false;
    }
};