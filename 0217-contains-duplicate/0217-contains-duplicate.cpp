class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // unordered_map<int,int>mp;
        // for(int i :nums){
        //     if(mp[i]>=1) return true;
        //    else mp[i]++;
        // }
        // return false;
        set<int>s(nums.begin(),nums.end());
        return s.size()<nums.size();
    }
};