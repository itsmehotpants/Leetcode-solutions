class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int bit=0;bit<=31;bit++){
            int temp = (1<<bit);
            int c0=0,c1=0;
            for(int &i:nums){
                if((i&temp)==0){
                    c0++;
                } 
                else c1++;
            }
            if(c1%3==1){
                ans = (ans|temp);
            }
        }
        return ans;
    }
};