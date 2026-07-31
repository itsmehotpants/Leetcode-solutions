class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n =nums.size();
        for(int i:nums) mp[i]++;
        for(auto&[num,freq]:mp){
            if(freq>n/2) return num;
        }
        return 0;
    }
};