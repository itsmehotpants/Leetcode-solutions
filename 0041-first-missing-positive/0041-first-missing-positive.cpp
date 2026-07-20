class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i:nums) mp[i]++;
        for(int i =1;i<INT_MAX;i++){
            if(!(mp.count(i)>0)) return i;
        }
        return -1;
    }
};