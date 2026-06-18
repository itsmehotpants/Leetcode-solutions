class Solution {
public:
    double angleClock(int hour, int mins) {
        double total_hour = double(hour) + double(mins)/60;
  
        double hr_angle = total_hour*30;
     double min_angle = mins*6;
        
        double res = abs(min_angle - hr_angle);
       
        return min(res,360-res);
        
    }
};