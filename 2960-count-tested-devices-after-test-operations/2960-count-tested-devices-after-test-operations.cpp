class Solution {
public:
    int countTestedDevices(vector<int>& bat) {
        int d= 0,ans=0;
        for(int i=0;i<bat.size();i++){
            if(bat[i]-d>0){
                ans++;
                d++;
            }
            else continue;
        }
        return ans;
    }
};