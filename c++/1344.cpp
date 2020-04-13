class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour == 12)
            hour = 0;
        double minute_angle = (double)minutes * 6;
        double hour_angle = (double)hour * 30 + 30 * (double)minutes / 60;
        if(minute_angle >= hour_angle)
            return min(minute_angle - hour_angle, 360 - (minute_angle - hour_angle));
        else{
            return min(hour_angle - minute_angle, 360 - (hour_angle - minute_angle));
        }
    }
};