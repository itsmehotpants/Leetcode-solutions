class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string>ans;

        for(int x:nums){
            string s;

            while(x>=(1LL<<25)){
                s+='z';
                x-=(1LL<<25);
            }
            
            for(int i =24;i>=0;i--){
                if(x&(1LL<<i)){
                    s+=char('a'+i);
                }
            }
                ans.push_back(s);
            
        }
    return ans;
    }
};