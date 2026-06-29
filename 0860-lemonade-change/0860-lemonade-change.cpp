class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int have5=0,have10=0,have20=0;
        for(int i:bills){
            if(i==5) have5++;
            if(i==10){
                if(have5==0) return false;
                else{
                    have10++;
                    have5--;
                }
            }
            if(i==20){
                
               if(have10>0 && have5>0){
                have10--;
                have5--;
               }
               else if(have5>2){
                have5-=3;
               }
               else return false;
            }
        }
        return true;

    }
};