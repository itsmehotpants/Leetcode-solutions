class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // unordered_map<int,int>mp;
        // int n =nums.size();
        // for(int i:nums) mp[i]++;
        // for(auto&[num,freq]:mp){
        //     if(freq>n/2) return num;
        // }
        // return 0;
        int c1=-1,cnt=0;
        for(int i:nums){
            if(cnt==0) c1=i;
            if(c1==i) cnt++;
            else cnt--;
        }
        return c1;
    }
};