class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour = hour%12;
        double degree = hour * 30;
        degree += 0.5 * minutes;
        degree -= minutes * 6;
        if(abs(degree) > 180){
            return 360 - abs(degree);
        }
        return abs(degree);
    }
};
